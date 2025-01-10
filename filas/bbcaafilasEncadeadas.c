#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct No{
    Item dado;
    struct No *prox;
}No;

No *criar_no(int x){
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = x;
    novo->prox = NULL;

    return novo;

}

typedef struct cabeca{
    No *prox;
    No *ultimo; 
    int tam;
}cabeca;

int vazio(cabeca *lista){
    return (lista->prox == NULL);
}

void enfileria(cabeca *f, Item x){
    No *novo = criar_no(x);

    if(novo){
        if(vazio(f)){
            f->prox = x;
        }
        
        else f->ultimo->prox = x;

        f->ultimo = novo;
        novo->prox = NULL;
        f->tam++;
    }
}

Item desenfilera(cabeca *f){
    No *lixo = f->prox; 
    f->prox = lixo->prox; 
    if(vazio(f)) f->ultimo = NULL;
    f->tam--;

    Item x = lixo->dado;
    free(lixo);
    return x;
}





