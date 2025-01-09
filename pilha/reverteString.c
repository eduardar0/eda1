#include<stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef char Item;

typedef struct pilha{
    Item *dado;
    int topo;
    
    }pilha;

    pilha *criar(int maxN){
        pilha *p = malloc(sizeof(pilha));
        p->dado = malloc(maxN*sizeof(Item));
        p->topo = 0;
        return p;
    }

    void empilhar(pilha *p, Item x){
        p->dado[p->topo++] = x;
    }

    Item desempilha(pilha *p){
        return p->dado[--p->topo];
    }

    int vazio(pilha *p){
        return p->topo == 0;
    }

    Item espia(pilha *p){
        return p->dado[p->topo-1];
    }

    int main(){
        pilha *criar_p = criar(10); 

        char string[100];

    printf("Digite uma string: ");
    scanf("%s", string);
    
        for(int i = 0; string[i] != '\0'; i++){
                empilhar(criar_p, string[i]);
        }

        printf("string invertida: \n");

        while(!vazio(criar_p)){
            printf("%c", desempilha(criar_p));
        }
        printf("\n");

        free(criar_p->dado);
        free(criar_p);

        return 0;
    }