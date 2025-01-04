#include <stdio.h>
#include <stdlib.h>

typedef int Item; 

typedef struct {
    Item *item;
    int primeiro, ultimo;
    int capacidade; // Adicionado para controlar o tamanho da fila
} Fila;

// Função para criar a fila com capacidade definida
Fila *criar(int maxN) {
    Fila *p = malloc(sizeof(Fila));
    p->item = malloc(maxN * sizeof(Item)); // Alocação correta para os itens
    p->primeiro = p->ultimo = 0;
    p->capacidade = maxN; // Armazena a capacidade máxima
    return p; 
}

// Verifica se a fila está vazia
int vazia(Fila *f) {
    return f->primeiro == f->ultimo;
}

// Verifica se a fila está cheia
int cheia(Fila *f) {
    return (f->ultimo + 1) % f->capacidade == f->primeiro;
}

// Remove um item da fila
int desenfileira(Fila *f) {
    if (vazia(f)) {
        printf("Erro: Fila vazia! Não é possível desenfileirar.\n");
        return -1; // Valor especial para indicar falha
    }
    Item removido = f->item[f->primeiro];
    f->primeiro = (f->primeiro + 1) % f->capacidade; // Avança na fila circular
    return removido;
}

// Insere um item na fila
void enfileira(Fila *f, int y) {
    if (cheia(f)) {
        printf("Erro: Fila cheia! Não é possível enfileirar.\n");
        return;
    }
    f->item[f->ultimo] = y;
    f->ultimo = (f->ultimo + 1) % f->capacidade; // Avança na fila circular
}

// Imprime os elementos da fila
void imprime(Fila *f) {
    if (vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila [capacidade = %d]: ", f->capacidade);
    for (int i = f->primeiro; i != f->ultimo; i = (i + 1) % f->capacidade) {
        printf("%d ", f->item[i]);
    }
    printf("\n");
}

// Função principal para testar
int main() {
    Fila *fila = criar(5); // Fila com capacidade 5

    // Teste: enfileirar elementos
    enfileira(fila, 10);
    enfileira(fila, 20);
    enfileira(fila, 30);
    imprime(fila);

    // Teste: desenfileirar elementos
    printf("Desenfileirado: %d\n", desenfileira(fila));
    imprime(fila);

    // Teste: tentar enfileirar em fila cheia
    enfileira(fila, 40);
    enfileira(fila, 50);
    enfileira(fila, 60); // Este deve falhar, pois a fila estará cheia
    imprime(fila);

    // Limpeza
    free(fila->item);
    free(fila);

    return 0;
}
