
#include <stdio.h>


typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;

typedef struct Lista {
    No *cabeca;
    No *ultimo;
} Lista;

Lista* criarLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->cabeca = NULL;
    lista->ultimo = NULL;
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
        novo->ant = NULL;
    } else {
        novo->ant = lista->ultimo; // Novo nó aponta para o antigo último
        lista->ultimo->prox = novo; // O antigo último aponta para o novo
        lista->ultimo = novo; // Atualiza o ponteiro ultimo
    }
}

