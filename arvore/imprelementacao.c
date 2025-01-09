#include <stdio.h>
#include <stdlib.h>

// Define o tipo de item que será armazenado nos nós da árvore
typedef int Item;

// Declaração da estrutura do nó da árvore
typedef struct node {
    Item item;        // Valor armazenado no nó
    struct node *pai; // Ponteiro para o nó pai
    struct node *esq; // Ponteiro para o filho esquerdo
    struct node *dir; // Ponteiro para o filho direito
} no;

// Função para criar uma árvore binária com um nó raiz
no *criar_arvore(Item x, no *p, no *e, no *d) {
    // Aloca memória para o nó raiz
    no *raiz = (no *)malloc(sizeof(no));
    if (raiz == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    // Inicializa os campos do nó raiz
    raiz->item = x;    // Atribui o valor ao nó
    raiz->pai = p;     // Define o nó pai
    raiz->esq = e;     // Define o filho esquerdo
    raiz->dir = d;     // Define o filho direito

    return raiz;       // Retorna o ponteiro para o nó raiz
}
