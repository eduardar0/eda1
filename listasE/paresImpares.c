#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime_lista(celula *l) {
    celula *atual = l->prox; // Começa no primeiro elemento útil
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *atual = l->prox; // Começa no primeiro nó após a cabeça
    celula *fim_l1 = l1;     // Aponta para o final de l1
    celula *fim_l2 = l2;     // Aponta para o final de l2

    while (atual != NULL) {
        celula *proximo = atual->prox; // Salva o próximo nó antes de modificar
        if (atual->dado % 2 != 0) {
            fim_l1->prox = atual; // Adiciona o nó a l1
            fim_l1 = atual;       // Atualiza o fim de l1
        } else {
            fim_l2->prox = atual; // Adiciona o nó a l2
            fim_l2 = atual;       // Atualiza o fim de l2
        }
        atual->prox = NULL; // Remove o nó original
        atual = proximo;    // Avança para o próximo
    }

    // Garante que ambas as listas terminam em NULL
    fim_l1->prox = NULL;
    fim_l2->prox = NULL;
}

int main() {
    // Criando os nós da lista original
    celula l = {0, NULL}, l1 = {0, NULL}, l2 = {0, NULL};
    celula n1 = {10, NULL}, n2 = {4, NULL}, n3 = {-9, NULL}, n4 = {2, NULL}, n5 = {7, NULL}, n6 = {10, NULL};

    l.prox = &n1;
    n1.prox = &n2;
    n2.prox = &n3;
    n3.prox = &n4;
    n4.prox = &n5;
    n5.prox = &n6;

    printf("Lista original:\n");
    imprime_lista(&l);

    divide_lista(&l, &l1, &l2);

    printf("\nLista l1 (ímpares):\n");
    imprime_lista(&l1);

    printf("\nLista l2 (pares):\n");
    imprime_lista(&l2);

    return 0;
}
