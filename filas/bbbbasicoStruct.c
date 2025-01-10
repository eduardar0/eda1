#include<stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct{
    Item *dado;
    int primeiro, ultimo;
    int tam;
}Fila;


Fila *criar(maxN){
    Fila *f = malloc(sizeof(Fila));
    f->dado = malloc(maxN*sizeof(Item));
    f->primeiro=f->ultimo=0;
    f->tam = maxN;

    return f;
}

void enfilerar(Fila *f, Item x){

    if(f->ultimo < f->tam ){
    f->dado[f->ultimo++] = x; 
    }
    else {
    printf("Fila cheia!\n");
    }

}

int vazio(Fila *f){
    return f->ultimo == f->primeiro;
}

Item desenfilera(Fila *f) {
    if (!vazio(f)) {
        return f->dado[f->primeiro++];
    } else {
        printf("Fila vazia!\n");
        return -1; // Valor indicando erro
    }
}


void imprime(Fila *f){
    printf("Primeiro elemento = %d, ultimo elemento = %d \n", f->primeiro, f->ultimo );

    for(int i = f->primeiro; i<f->ultimo; i++){
        printf("F[%d] = %d\n", i, f->dado[i]);

        printf("\n");

    }

}

int main() {
    Fila *f = criar(5);
    enfilerar(f, 10);
    enfilerar(f, 20);
    imprime(f);

    desenfilera(f);
    imprime(f);

    return 0;
}