#include <stdio.h>
#include <stdlib.h>

// Definições
#define info(A) (A.info)
#define key(A) (A.chave)
#define less(A, B) ((A) < (B))
#define eq(A, B) ((A) == (B))

// Troca de itens
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

// Tipo de dado
typedef struct {
    int chave;
    int info;
} Item;

// Nó da árvore
typedef struct STnode {
    Item item;
    struct STnode *esq, *dir;
} STnode;

// Função para criar um novo nó
STnode* new(Item x, STnode* e, STnode* d) {
    STnode* no = (STnode*) malloc(sizeof(STnode));
    no->esq = e;
    no->dir = d;
    no->item = x;
    return no;
}

// Função para remover um nó da árvore
STnode* STdelete(STnode* no, Item item_remover) {
    if (no == NULL) return NULL;

    int valor = key(no->item);

    if (item_remover.info < valor) {
        no->esq = STdelete(no->esq, item_remover);
    } else if (item_remover.info > valor) {
        no->dir = STdelete(no->dir, item_remover);
    } else {
        // Caso o nó tenha apenas o filho esquerdo
        if (no->dir == NULL) {
            STnode* filho = no->esq;
            free(no);
            return filho;
        }
        // Caso o nó tenha apenas o filho direito
        if (no->esq == NULL) {
            STnode* filho = no->dir;
            free(no);
            return filho;
        }
        // Caso o nó tenha ambos os filhos
        remover_sucessor(no);
    }
    return no;
}

// Função para remover o sucessor
void remover_sucessor(STnode* raiz) {
    STnode* sucessor = raiz->dir;
    STnode* pai = raiz;

    // Procurar o menor nó da subárvore direita (sucessor)
    while (sucessor->esq != NULL) {
        pai = sucessor;
        sucessor = pai->esq;
    }

    // Ajustar os ponteiros
    if (pai->esq == sucessor) pai->esq = sucessor->dir;
    else pai->dir = sucessor->dir;

    // Substituir o item do nó raiz pelo do sucessor
    raiz->item = sucessor->item;
    free(sucessor);
}
