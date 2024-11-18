#include <stdio.h>

typedef struct celula {
    int dado;
   struct celula *prox;
} celula;

celula *busca(celula *le, int x){

    celula *atual = le->prox;
    
    while(atual != NULL){

        if(atual->dado == x){
            return atual; //retorna o no procurado
        }
    atual = atual->prox; //segue para o proximo
    }

    return NULL;
}
celula *busca_rec(celula *le, int x){
    if(le ==NULL){ //se for vazio, retorna null
        return NULL;
    }
    if(le->dado == x){
        return le; //condição de parada, retorna o no que x
    }
    busca_rec(le->prox, x);
}



// int main() {
//     // Exemplo simples para testar o código
//     celula cabeca = {0, NULL}; // Nó cabeça
//     celula n1 = {1, NULL};
//     celula n2 = {2, NULL};

//     // Configurando a lista: cabeça -> n1 -> n2
//     cabeca.prox = &n1;
//     n1.prox = &n2;

//     // Testa a busca
//     celula *resultado = busca(&cabeca, 2); // Procurando o valor 2
//     if (resultado != NULL) {
//         printf("Encontrado: %d\n", resultado->dado);
//     } else {
//         printf("Nao encontrado\n");
//     }

//     return 0;
// }