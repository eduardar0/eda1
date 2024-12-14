#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct {
    Item *item;    
    int primeiro;  
    int ultimo;    
} Fila;

// Cria uma fila com capacidade máxima `maxN`
Fila *criar(int maxN) {
    Fila *p = malloc(sizeof(Fila));
    if (p == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
    p->item = malloc(maxN * sizeof(Item));
    if (p->item == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para os itens da fila.\n");
        free(p);
        exit(EXIT_FAILURE);
    }
    p->primeiro = p->ultimo = 0;
    return p;
}

// Verifica se a fila está vazia
int vazia(Fila *f) {
    return f->primeiro == f->ultimo;
}

// Remove e retorna o item no início da fila
int desenfileira(Fila *f) {
    if (vazia(f)) {
        fprintf(stderr, "Erro: Tentativa de desenfileirar de uma fila vazia.\n");
        exit(EXIT_FAILURE);
    }
    return f->item[f->primeiro++];
}

// Adiciona um item ao final da fila
void enfileira(Fila *f, int y) {
    f->item[f->ultimo++] = y;
}

// Função para liberar a memória da fila
void destruir(Fila *f) {
    free(f->item);
    free(f);
}

// Função para imprimir o estado da fila
void imprime(Fila *f) {
    printf("\nFILA p=%d e u=%d\n", f->primeiro, f->ultimo);

    // Imprime os índices
    for (int i = f->primeiro; i < f->ultimo; i++) 
        printf(" F[%d] |", i);
    printf("\n");

    // Imprime os valores
    for (int i = f->primeiro; i < f->ultimo; i++) 
        printf(" %3d |", f->item[i]);
    printf("\n");
}

int main() {
    // Teste com a primeira fila
    printf("\n\nCriando a fila e enfileirando 10 elementos\n");
    Fila *fila1 = criar(100);
    for (int i = 0; i < 10; i++) 
        enfileira(fila1, i);

    imprime(fila1);

    printf("\n\nDesenfileirando os 3 primeiros elementos\n");
    for (int i = 0; i < 3; i++) 
        desenfileira(fila1);

    imprime(fila1);

    // Teste com a segunda fila
    printf("\n\nCriando outra fila e enfileirando 5 elementos\n");
    Fila *fila2 = criar(400);
    for (int i = 0; i < 5; i++) 
        enfileira(fila2, i * 10);

    imprime(fila2);

    // Liberando as filas
    destruir(fila1);
    destruir(fila2);

    return 0;
}
