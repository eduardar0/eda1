#include<stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct{
    Item *dado;
    int primeiro, ultimo;
    int tam;
}Fila;


Fila *criar(int maxN){
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
Item desenfilera(Fila *f) {
    if (!vazio(f)) {
        return f->dado[f->primeiro++];
    } else {
        printf("Fila vazia!\n");
        return -1; // Valor indicando erro
    }
}


int vazio(Fila *f){
    return f->ultimo == f->primeiro;
}
//caso a fila esteja cheia e haja espaços vazios é possivel redimensionar a fila 
void redimensiona1(Fila *f){

    f->tam *= 2;
    f->dado = realloc(f->dado, f->tam * sizeof(Item));
    //acho que nao serve aqui por que a fila é circular 
}

void imprime(Fila *f){
    printf("Primeiro elemento = %d, ultimo elemento = %d \n", f->primeiro, f->ultimo );

    for(int i = f->primeiro; i<f->ultimo; i++){
        printf("F[%d] = %d", i, f->dado[i]);

        printf("\n");

    }

}


int main() {

    printf("Criando fila e enfileirando 10 elementos\n");
    Fila *fila = criar(10); //usa função de criar fila 

    for(int i =0; i<10; i++) enfilerar(fila, i);
    imprime(fila); 

    printf("Desenfilerando os 3 primeiros elementos\n");

    for(int i =0; i<3; i++) desenfilera(fila);

    imprime(fila); 



    return 0;
}