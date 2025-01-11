#include <stdio.h>
#include <stdlib.h>

// Define o tipo de item que será armazenado nos nós da árvore
typedef int Item;

// Estrutura do nó da árvore
typedef struct No {
    Item item;
    struct No *pai;
    struct No *esq, *dir;
} No;

// Função para criar um nó da árvore
No *criar_arvore(Item x, No *pai, No *esq, No *dir) {
    No *raiz = malloc(sizeof(No));
    raiz->pai = pai;
    raiz->esq = esq;
    raiz->dir = dir;
    raiz->item = x;
    return raiz;
}

// Função que cria o torneio e retorna a raiz da árvore
No *torneio(int *v, int l, int r) {
    if (l == r) 
        return criar_arvore(v[l], NULL, NULL, NULL);

    int m = (l + r) / 2;

    // Cria os nós esquerdo e direito recursivamente
    No *esq = torneio(v, l, m);
    No *dir = torneio(v, m + 1, r);

    // Define o pai dos nós esquerdo e direito
    esq->pai = dir->pai = criar_arvore(esq->item > dir->item ? esq->item : dir->item, NULL, esq, dir);

    return esq->pai;
}

// Função para calcular o número de nós da árvore
int numero_nos(No *elemento) {
    if (elemento == NULL) return 0;
    return 1 + numero_nos(elemento->esq) + numero_nos(elemento->dir);
}

// Função para calcular a altura da árvore
int altura(No *elemento) {
    if (elemento == NULL) return 0;
    int h_esq = altura(elemento->esq);
    int h_dir = altura(elemento->dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

int main() {
    int v[8] = {5, 1, 7, 4, 3, 4, 6, 8}; 

    // Cria a árvore de torneio
    No *teste = torneio(v, 0, 7);

    // Imprime o vencedor e os semifinalistas
    printf("VENCEDOR: %d\n", teste->item);
    printf("SEMIFINAL: %d X %d\n", teste->esq->item, teste->dir->item);

    // Exibe o número de nós e a altura da árvore
    printf("NÚMERO DE NÓS: %d\n", numero_nos(teste));
    printf("ALTURA DA ÁRVORE: %d\n", altura(teste));

    return 0;
}
