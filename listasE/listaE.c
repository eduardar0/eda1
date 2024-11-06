#include <stdio.h>
#include <stdlib.h>


struct ElementoLista
{
    int valor;
    struct ElementoLista *prox; // o ponteiro vai ser do tipo criado na struct
    //guardar o endereço de memoria do proximo elemento
    
};//cabeça

typedef struct ElementoLista item; //define um novo tipo de dados  
//pode usar item toda vez que quiser se referiri a um item da lista

void imprime(item *cabeca){//cabeca definida no tpo item

item *atual = cabeca->prox;
int i =0; //i para contar quantos itens tem na lista
while(atual != NULL){

    atual = atual->prox;
}
printf("total de itens na lista %d\n", i);
}


void insereFim(item *cabeca, int valor){
    item *novo = (item*)malloc(sizeof(item)); //malloc do tamanho de item
    //malloc usada para alocar dinamicamente um bloco de memoria no heap
    //permanece alocada ate um frre
    // o malloc foi transformado em um ponteiro de tipo item

    novo ->prox = NULL; //ultimo da lista
    novo ->valor = valor;
//-> são usadas para acessar membros deuma struct ou classe atravez de um ponteiro, ou seja, achando seu endereço na memoria
//tipo o que o . faz, Quando você está acessando uma variável da estrutura diretamente (não é um ponteiro).
    item *atual = cabeca;

    while(atual ->prox != NULL){
        atual = atual->prox; // vai varreando ate achar o uktimo item
    }
    
    atual->prox = novo;
}



void libera(item *cabeca) {
    item *atual = cabeca->prox; // ponteiro para o próximo item na lista
    item *liberado; // ponteiro para o item a ser liberado

    while (atual != NULL) {
        liberado = atual;
        atual = atual->prox;
        
        printf("Liberado o item de valor %3d na posição %p\n", liberado->valor, (void *)liberado);
        
        free(liberado); // libera a memória do item atual
    }

    // Caso também precise liberar o nó da cabeça:
    free(cabeca);
}

int main(){

    item cabeca;
    cabeca.prox = NULL; //lista ta vazia por enquanto

    printf("tamanho do item: %ld\n", sizeof(item));




    return 0;
}