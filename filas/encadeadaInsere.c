#include <stdio.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct Lista {
    No *cabeca;
    No *ultimo; // Apontador direto para o último nó
} Lista;

Lista* criarLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->cabeca = NULL; 
    lista->ultimo = NULL; // Inicialmente não há elementos
    return lista;
}

// Função para adicionar ao final
void adicionarFim(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    
    if (lista->cabeca == NULL) { // Lista vazia
        lista->cabeca = novo;
        lista->ultimo = novo;
    } else {
        lista->ultimo->prox = novo;
        lista->ultimo = novo; // Atualiza o último
    }
}
 