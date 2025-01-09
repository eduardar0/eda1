//fuções basicas para uma pilha: empilha, desempilha, vazio, espia, criar 
#include<stdio.h>
int *pilha;
int t;

int criar(int n){

    pilha = malloc(n * sizeof(pilha));
    t = 0;
}

void empilha(int x){

    pilha[t++] = x;

}

int desempilha(){
    return pilha[--t];
}

int vazio(){
    return t == 0;
}

int  espia(){
    return pilha[t-1];
}

//principais funções para implementação estatica 

