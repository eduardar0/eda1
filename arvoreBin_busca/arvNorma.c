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
    int h_esq = 1+ altura(elemento->esq);
    int h_dir= 1 + altura(elemento->dir);

    return 1 + ( h_esq>h_dir ? h_esq : h_dir);
}

//ABB AQUI

No *busca_binaria(No *no, Item x){
    if(no==NULL || no->item == x) return no; 

    if(no->item<x) return busca_binaria(no->dir, x);
    else return busca_binaria(no->esq, x);
}

No *insert(No *no, Item tal){
    if(no == NULL) return criar_arvore(tal, NULL, NULL,NULL);

    if(no->item < tal) no->dir = insert(no->dir, tal);

    else no->esq = (no->esq, tal);

    return no;
}
No *sucessor(No *raiz){

}

No *minimo(No *raiz){

    if(raiz->esq == NULL) return minimo(raiz->esq);
}

No *ancestral_direita(No *no){
    if(no == NULL) return NULL;
    //nao tenho pai  = nao ter ansestral, ou  ser dascendente esquerdo 

    if(no->pai == NULL || no->pai->esq == no) return no->pai;

    // Caso 1: Se não tem pai (é a raiz) ou é filho à esquerda, o pai é o ancestral à direita

    return ancestral_direita(no->pai);    
}


No *sucessor(No *no){
    //maior imediato dela 
    //como acha? sempre maior - vaip direita 
    //o menor dos maiores, vai para a direita e esquerda ate achar null 
    //se nao tiver sucessor a diretia, primeiro ancestral a direita 
    if(no->dir != NULL) return minimo(no->dir);

    return ancestral_direita(no);

}

No *remocao(No *no, Item x){
    //se não tiver filho nao precisa fazer nada 
    // Caso 1: Nó folha (sem filhos)
    if (no->dir == NULL && no->esq == NULL) {
        free(no);
        return NULL;
    }
    //se tiver so um filho, o avô assume no lugar do filho 
    //se eu for filho a esquerda, meu pai assume meu filho a esquerda

    if(no->item < x){
        no->esq = remocao(no->esq, x);
    }

}

int main(){

}