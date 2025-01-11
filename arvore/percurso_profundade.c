//feito com pilha
//3 tipos: 
/*
- pre-ordem: 1- raiz, 2- esquerda, 3- direita (notaçõa polonesa)
- pos-ordem: 1- esquerda, 2- direira, 3- raiz (polonesa inversa)
- Inordem: 1- esquerda, 2- raiz, 3- direita (normal)
*/
//Diferentes tipos d epercursos, geram diferentes sequencias de nós 
//percurso em lrgura (filas)
/*percurso por nivel : os nós soa visitados na oredem dis niveis em que estãp
1 -no 0 (raiz), depois 1, 2, 3....
*/
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


typedef int Item;
typedef struct{
    Item *dado;
    int primeiro, ultimo;
    int tam;
}Fila;


Fila *criar(int maxN){
    Fila *f = malloc(sizeof(Fila));
    f->dado = malloc(maxN*sizeof(Item));
    f->primeiro=f->ultimo=0;
    f->tam = maxN;

    return f;
}

void enfilerar(Fila *f, Item x){

    if(f->ultimo < f->tam ){
    f->dado[f->ultimo++] = x; 
    }
    else {
    printf("Fila cheia!\n");
    }

}

int vazio(Fila *f){
    return f->ultimo == f->primeiro;
}

Item desenfilera(Fila *f) {
    if (!vazio(f)) {
        return f->dado[f->primeiro++];
    } else {
        printf("Fila vazia!\n");
        return -1; // Valor indicando erro
    }
}


void imprime(Fila *f){
    printf("Primeiro elemento = %d, ultimo elemento = %d \n", f->primeiro, f->ultimo );

    for(int i = f->primeiro; i<f->ultimo; i++){
        printf("F[%d] = %d", i, f->dado[i]);

        printf("\n");

    }

}

//caso a fila esteja cheia e haja espaços vazios é possivel redimensionar a fila 
void redimensiona1(Fila *f){

    f->tam *= 2;
    f->dado = realloc(f->dado, f->tam * sizeof(Item));
    //acho que nao serve aqui por que a fila é circular 
}





void pre_ordem(No *raiz){

if(raiz != NULL){
    printf("%d", raiz->item);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}
}

void pos_ordem(No *raiz){

    if(raiz!=NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf(" %d", raiz->item);
        
    }
}

void inordem(No *raiz){

    if(raiz!=NULL){
        pos_ordem(raiz->esq);
        printf(" %d", raiz->item);
        pos_ordem(raiz->dir);
        
    }
}

