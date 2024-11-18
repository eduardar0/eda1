#include <stdio.h>
#include <stdlib.h> //funões de alocação de memoria

// Definição da struct celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para inserir um elemento no início da lista
void insere_inicio(celula *le, int x) {
    celula *nova = malloc(sizeof(celula));
    if(nova == NULL){
        perror("Erro, memoria nao alocada");
        exit(1);
    }
    nova ->dado = x;
    nova->prox = le->prox;
    le->prox = nova; 
}

void insere_antes(celula *le, int x, int y) 
{
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual!= NULL && atual->dado != y)
    {
        anterior = atual;
        atual = atual->prox;
    }
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) {
    perror("Erro ao alocar memória");
    exit(1);
    }

    novo->dado = x;
    novo->prox = atual;
    anterior->prox = novo;
}