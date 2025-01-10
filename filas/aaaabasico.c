//estatica 
//imediatamente astras dos outros 
//os dados que estão na frente sao processados primeiro 
//operações basicas: 
/*vazia
tamanho 
primeiro-busca_incio
utimo busca_fim
desenfilera-remove_inicio
*/

#include<stdio.h>

#define N 7 

int fila[N];
int p, u;

void criar_fila(){
    p = u = 0; //quando p = u é por que a fila ta vazia, se p == N, ent ta cheia 
}

int vazia(){
    return p == u; 
}

int desenfilera(){
    return fila[p++];
}
int enfilera(int x){
    fila[u++] = x;
}

//se a fila ta cheia, nao tem como inserir nela novamente, mesmo que haja espaços vazios 

//lista circular 

void enfilera_Circ(int x){
    fila[u++] = x;
    if(u ==N){
        u=0;;
    }
    
}

int desenfilera(){
    int x =fila[p++];
    if(p==N) p=0;
    return x;
}