#include <stdlib.h> 
#include<stdio.h>


typedef struct fila {
    int *dados; 
    int N, p, u; // N é o número total de "espaços" na fila, p é o índice do primeiro, u é o índice do próximo disponível
} fila;


int enfileira(fila *f, int x) {
    // Verifica se a fila precisa ser redimensionada
    if ((f->u + 1) % f->N == f->p) {
        // Calcula o novo tamanho da fila
        int novo_tamanho = f->N * 2; 
        int *novo_dados = (int *)malloc(novo_tamanho * sizeof(int)); 
        if (!novo_dados) return 0; // Falha na alocação
        
        // Copia os dados para o novo vetor considerando a circularidade
        int i, j = 0; 
        for (i = f->p; i != f->u; i = (i + 1) % f->N) {
            novo_dados[j++] = f->dados[i];
        }
        
        free(f->dados); // Libera a memória antiga
        f->dados = novo_dados; 
        f->N = novo_tamanho;
        f->p = 0;
        f->u = j; // Atualiza o índice de final
    }

    // Insere o elemento na fila
    f->dados[f->u] = x; 
    // Atualiza o índice final
    f->u = (f->u + 1) % f->N;
    return 1; 
}


