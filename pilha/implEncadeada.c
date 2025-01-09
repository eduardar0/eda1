#include<stdio.h>

typedef struct No{
    int dado;
    struct No *prox;
}No;

No* criarNo(int valor) //função criar no da encadeada
{
    No *novoNo = (No* )malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo ->prox = NULL;

    return novoNo;
}


typedef int Item; 

typedef struct pilha {
    No *prox;       // Ponteiro para o topo da pilha
    No *ultimo;     // Ponteiro para o último nó (opcional)
    int topo;  // Contador de itens na pilha
} pilha;


pilha* criar_pilha(int maxN){
    pilha *p = (pilha*) malloc(sizeof(pilha));
    p->prox = NULL;
    p->ultimo = NULL;
    p->topo = 0;
}

// Função para criar uma pilha


int vazia(pilha *p){
    return p->topo == 0;
}

void empilhar(pilha *p, Item x){
    No *novo = criarNo(x);

    if(novo){
        if(vazia(p)){
            p->ultimo = novo;
        }

        novo->prox = p->prox; //atualiza o valor do no novo 
        p->prox = novo; //atualiza dentro da pilha
        p->topo++;  //atualiza o topo 

    }
}

Item desempilha(pilha *p){
    No *tp = p->prox;
    p->prox = tp->prox; 

    if(tp == p -> ultimo){
        p -> ultimo = NULL;
    }
    p->topo--;
    Item x = tp->dado;

    free(tp);
    return x;

}