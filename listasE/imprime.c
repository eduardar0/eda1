#include <stdio.h>

typedef struct celula {
    int dado;
   struct celula *prox;
} celula;

void imprime (celula *le){
    celula *atual = le->prox;
    if (atual == NULL) { // Caso a lista esteja vazia
        printf("NULL\n");
        return;
    }
    while (atual!=NULL)
    {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");


}

void imprime_rec (celula *le){

    if (le == NULL || le->prox == NULL) { // Caso base: fim da lista ou fim da lista
        printf("NULL\n");
        return;
    }

    printf("%d -> ", le->prox->dado); //nao contar a cabeça

    imprime_rec(le->prox);

}