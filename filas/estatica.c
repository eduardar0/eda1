#include <stdio.h>

#define N 7

int fila[N];

int p, u;

void criar_fila(){
    p = u = 0; 
}

// VAZIA

int vazia(){
    return p == u; 
}
//retorna true se a lista for vazia 

//remoção no inicio da fila 

//fila[p]

// p vai virar p+1 

int desenfilera(){
    int x = fila[p++];
    if (p == N) p =0;
    return x;
}

//inserção no fim da fila 

int enfilera(int y){
    return fila[u++] = y;

    if(u==N) u =0; // se a fila estiver cheia, volta pro inicio 
} // u é a variavel de final




//fila cheia 
//u == N (ultima posição pe do tamanho do vetor)