#include <stdio.h>
#include <stdlib.h>


// Define o tipo de item que será armazenado nos nós da árvore
typedef int Item;

typedef struct No{
    Item item;
    No *pai;
    No *esq, *dir;

}No;

No *criar_arvore(Item x, No *pai, No* esq, No *dir){
    No *raiz = malloc(sizeof(No));
    raiz->pai = pai;
    raiz->esq = esq;
    raiz->dir = dir;
    raiz->item = x;
    return raiz;
}

No *avo(No *elemento){
    if(elemento != NULL && elemento->pai != NULL) return elemento->pai->pai;

    return NULL;

}

No *tio(No *elemento){
    No *vovo = avo(elemento);
    if(vovo == NULL) return NULL;
    if(vovo->dir == elemento->pai) return vovo->esq;

    return vovo->dir;
}

No *irmao(No *elemento){
    if((elemento != NULL) && (elemento->pai != NULL)){
        if(elemento->pai->esq == elemento) return elemento->pai->dir;
        else return elemento->pai->esq;
    }

    return NULL;
}

No *busca_linear(No *elemento, Item x){

    if(elemento ==NULL || elemento->item == x) return elemento; 

    No *busca_esquerda = busca_linear(elemento->esq, x);
    if(busca_esquerda!=NULL) return busca_esquerda;

    return busca_linear(elemento->dir, x);

}

int numero_nos(No *elemento){
    if(elemento == NULL) return 0; 

    return 1 + numero_nos(elemento->esq) + numero_nos(elemento->dir); 
}

int altura(No *elemento){
    if(elemento==NULL) return 0; 
    int h_esq =  1 + altura(elemento->esq);
    int h_dir= 1+ altura(elemento->dir);

    return 1 + ( h_esq>h_dir ? h_esq : h_dir);
}


No *torneio(int *v, int l, int r){
    if(l==r) criar_arvore(v[l],NULL, NULL, NULL);

    int m = (l+r)/2;

    No *esq = torneio(v, l, m); 
    No *dir= torneio(v, m+1, r);


    int valor = esq->item > dir->item ? esq->item : dir->item;

    return criar_arvore(valor, NULL, esq, dir);

}