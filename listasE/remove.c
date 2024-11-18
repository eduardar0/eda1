
#include <stdio.h>
#include <stdlib.h> // Para funções de alocação de memória

// Definição da struct celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função que remove o elemento imediatamente após p
void remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        // Não há elemento para remover
        return;
    }
    
    celula *removido = p->prox; // Nó a ser removido
    p->prox = removido->prox;  // Ajusta o ponteiro para "pular" o nó removido
    free(removido);            // Libera a memória do nó removido
}

// Função que remove a primeira ocorrência de x na lista
void remove_elemento(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;

    // Percorre a lista procurando o valor x
    while (atual != NULL && atual->dado != x) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) { // Se encontrou x
        anterior->prox = atual->prox; // Ajusta os ponteiros
        free(atual);                  // Libera o nó que contém x
    }
}

// Função que remove todas as ocorrências de x na lista
void remove_todos_elementos(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL) {
        if (atual->dado == x) {
            celula *removido = atual;
            anterior->prox = atual->prox; // Ajusta os ponteiros para pular o nó removido
            atual = atual->prox;          // Avança para o próximo nó
            free(removido);               // Libera o nó removido
        } else {
            anterior = atual;             // Avança o ponteiro anterior
            atual = atual->prox;          // Avança o ponteiro atual
        }
    }
}
