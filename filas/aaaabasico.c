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
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#define TAM_INICIAL 7 // Tamanho inicial da fila
typedef int Item;

Item *fila;  // Agora fila é um ponteiro dinâmico
int p, u;
int N;  // Agora N é uma variável

// Função para criar a fila
void criar_fila(){
    N = TAM_INICIAL;
    fila = malloc(N * sizeof(Item)); // Aloca a memória para fila
    p = u = 0;
}

// Função para verificar se a fila está vazia
int vazia(){
    return p == u;
}

// Função para desenfileirar (remover o primeiro elemento)
int desenfilera(){
    int x = fila[p++];
    if(p == N) p = 0;
    return x;
}

// Função para enfileirar (adicionar um elemento)
void enfilera(int x){
    if(u == N) {
        printf("Fila cheia!\n");
        return;
    }
    fila[u++] = x;
}

// Função para enfileirar de forma circular
void enfilera_Circ(int x){
    fila[u++] = x;
    if(u == N) {
        u = 0;
    }
}

// Função para realocar a fila (dobrar o tamanho)
void realocar(void){
    N *= 2;  // Dobrar o tamanho da fila
    fila = realloc(fila, N * sizeof(Item)); // Realoca a memória
    if(fila == NULL) {
        printf("Erro ao realocar memória!\n");
        exit(1);  // Finaliza o programa em caso de erro de alocação
    }
}

void redimensiona(){
    N *= 2; 
    int *novo = malloc(N*sizeof(int));
    int j =0; 
    for (int i = p ; i < u; i++, j++){
        novo[j] = fila[i];
    } 
    p =0; 
    u =j;

    free(fila); 
    fila = novo;
}

void imprime_fila(){
    for(int i = p; i != u; i = (i + 1) % N) {
        printf("%d ", fila[i]);
    }
    printf("\n");
}

int main() {
    criar_fila();

    for(int i = 0; i < 7; i++) {
        enfilera(i);
    }

    imprime_fila();  // Imprime a fila

    printf("Desenfileirando: %d\n", desenfilera());
    imprime_fila();  // Imprime a fila após desenfileirar

    printf("Enfileirando elemento 10\n");
    enfilera(10);
    imprime_fila();  // Imprime a fila

    printf("Realocando a fila...\n");
    realocar();
    
    printf("Enfileirando mais elementos após realocação\n");
    for(int i = 11; i < 15; i++) {
        enfilera(i);
    }
    imprime_fila();  // Imprime a fila após a realocação

    return 0;
}
