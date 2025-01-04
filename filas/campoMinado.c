#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

// Estrutura para representar uma célula no campo
struct area {
    int visivel;  // Se a célula está visível ou não
    int item;     // O valor da célula (-1 para mina, 0 para vazio, etc.)
};

// Estrutura para representar uma célula na fila (para processamento)
struct celula {
    int l;        // Linha da célula
    int c;        // Coluna da célula
    STAILQ_ENTRY(celula) prox;  // Ponteiro para a próxima célula na fila
};

// Função para abrir o mapa a partir de uma célula inicial (l, c)
int abrir_mapa(int m, int n, struct area campo[m][n], int l, int c) {
    // Marca a célula inicial como visível
    campo[l][c].visivel = 1;

    // Se a célula contém uma mina (-1), o jogo termina
    if(campo[l][c].item == -1) {
        return campo[l][c].item; // -1 indica que perdeu
    }

    // Declaração da fila para o processamento das células
    struct head fila;

    // Criação da primeira célula para inserir na fila
    struct celula *no = malloc(sizeof(struct celula));
    no->l = l;
    no->c = c;

    // Inicializa a fila
    STAILQ_INIT(&fila);

    // Insere a célula inicial na fila
    STAILQ_INSERT_TAIL(&fila, no, prox);

    // Processa a fila enquanto houver células a serem exploradas
    while (!STAILQ_EMPTY(&fila)) {
        // Pega a primeira célula da fila
        struct celula *no2 = STAILQ_FIRST(&fila);

        // Remove a célula da fila após processá-la
        STAILQ_REMOVE_HEAD(&fila, prox);

        // Se a célula atual contém valor 0 (vazia), explorar as adjacentes
        if (campo[no2->l][no2->c].item == 0) {
            // Percorre as células vizinhas (8 direções)
            for (int i = no2->l - 1; i <= no2->l + 1; i++) {
                for (int j = no2->c - 1; j <= no2->c + 1; j++) {
                    // Verifica se a célula vizinha está dentro dos limites do mapa
                    if (i >= 0 && i < m && j >= 0 && j < n) {
                        // Se a célula vizinha ainda não foi visitada
                        if (campo[i][j].visivel == 0) {
                            // Marca a célula como visível
                            campo[i][j].visivel = 1;

                            // Cria uma nova célula para adicionar à fila
                            struct celula *no3 = malloc(sizeof(struct celula));
                            no3->l = i;
                            no3->c = j;

                            // Insere a nova célula na fila para ser processada
                            STAILQ_INSERT_TAIL(&fila, no3, prox);
                        }
                    }
                }
            }
        }

        // Libera a memória da célula processada
        free(no2);
    }

    // Retorna 0 quando o processo de abertura do mapa é concluído
    return 0;
}

int main() {
    // Exemplo de uso da função 'abrir_mapa'

    int m = 5, n = 5;  // Tamanho do mapa
    struct area campo[m][n];  // Mapa com áreas (campo)

    // Inicializando o campo (exemplo)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            campo[i][j].visivel = 0;  // Células inicialmente invisíveis
            campo[i][j].item = 0;     // Células inicialmente vazias
        }
    }

    // Definindo uma célula como mina (-1)
    campo[2][2].item = -1;

    // Chama a função 'abrir_mapa' com as coordenadas (0, 0) como inicial
    int resultado = abrir_mapa(m, n, campo, 0, 0);

    // Exibe o resultado
    printf("Resultado: %d\n", resultado);  // -1 se perdeu, 0 se conseguiu abrir células

    return 0;
}
