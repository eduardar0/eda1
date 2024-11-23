#include <stdio.h>
#include <stdlib.h> // Para funções de alocação de memória

// Definição da struct celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;
void remove_depois(celula *p){

if(p == NULL || p->prox ==NULL){
    return;
}

celula *removido = p->prox; //no a ser removido 
p->prox = removido->prox;
free(removido);

}
void remove_elemento(celula *p, int x){

    celula *anterior = p;
    celula *atual = p ->prox;

    while(atual != NULL && atual->dado != x){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual!=NULL){
        anterior->prox = atual->prox; //ajusta os ponteiros
        free(atual);
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
