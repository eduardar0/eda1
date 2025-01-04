#include <stdlib.h> // Para malloc
#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    // Aloca memória para o novo nó
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) {
        return NULL; // Falha na alocação
    }

    // Inicializa o novo nó
    novo->dado = x;
    novo->prox = NULL;

    // Caso a fila esteja vazia
    if (f == NULL) {
        return novo; // O novo nó se torna a cabeça
    }

    // Caso a fila já possua elementos, percorre até o último nó
    celula *atual = f;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Insere o novo nó no final da fila
    atual->prox = novo;

    // Retorna o ponteiro para o nó cabeça
    return f;
}
