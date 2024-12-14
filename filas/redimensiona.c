#include <stdio.h>
#include <stdlib.h>

int N = 4;     // Tamanho inicial da fila
int *fila;     // Ponteiro para o vetor que representa a fila
int p = 0;     // Índice do início da fila
int u = 0;     // Índice do fim da fila

// Função para redimensionar a fila circular
void redimensiona() {
    N *= 2; // Dobra o tamanho da fila para evitar redimensionamentos frequentes

    // Aloca um novo vetor com o dobro do tamanho
    int *novo = malloc(N * sizeof(int));
    if (novo == NULL) { // Verifica falha na alocação
        fprintf(stderr, "Erro: Falha ao alocar memória durante o redimensionamento.\n");
        exit(EXIT_FAILURE);
    }

    // Reorganiza os elementos da fila no novo vetor
    int j = 0; // Índice para o novo vetor
    for (int i = p; i < u; i++, j++) {
        novo[j] = fila[i];
    }

    // Ajusta os índices para a nova fila
    p = 0;  // O início da fila agora é 0
    u = j;  // O fim da fila corresponde ao número de elementos copiados

    // Libera o espaço do vetor antigo e substitui pelo novo
    free(fila);
    fila = novo;
}

// Função para testar o redimensionamento
int main() {
    // Inicializa a fila com tamanho inicial
    fila = malloc(N * sizeof(int));
    if (fila == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para a fila inicial.\n");
        exit(EXIT_FAILURE);
    }

    // Adiciona elementos à fila para forçar o redimensionamento
    for (int i = 0; i < 10; i++) {
        if (u == N) {
            redimensiona(); // Redimensiona quando a fila atinge o limite
        }
        fila[u++] = i;
    }

    // Exibe os elementos após o redimensionamento
    printf("Fila após redimensionamento:\n");
    for (int i = p; i < u; i++) {
        printf("%d ", fila[i]);
    }
    printf("\n");

    // Libera a memória da fila
    free(fila);

    return 0;
}
