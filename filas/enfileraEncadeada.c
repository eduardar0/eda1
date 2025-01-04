#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
typedef struct no {
    int valor;           // Pode ser substituído por qualquer tipo (Item)
    struct no *prox;     // Ponteiro para o próximo nó
} no;

// Estrutura para representar a fila
typedef struct cabeca {
    no *prox;           // Ponteiro para o primeiro nó da fila
    no *ultimo;         // Ponteiro para o último nó da fila
    int tam;            // Tamanho da fila
} cabeca;

// Função para criar um novo nó
no *criar_no(int x) {
    no *novo = malloc(sizeof(no));  // Aloca memória para o novo nó
    if (novo) {
        novo->valor = x;            // Atribui o valor ao nó
        novo->prox = NULL;          // Inicializa o ponteiro 'prox' como NULL
    }
    return novo;
}

// Função para verificar se a lista está vazia
int vazia(cabeca *lista) {
    return lista->prox == NULL;  // A lista está vazia se o ponteiro 'prox' for NULL
}

// Função para enfileirar (inserir no final da fila)
void enfileira(cabeca *lista, int x) {
    no *novo = criar_no(x);  // Cria um novo nó com o valor x

    if (novo) {  // Se a criação do nó for bem-sucedida
        if (vazia(lista)) {  // Se a fila está vazia
            lista->prox = novo;   // O novo nó é o primeiro da fila
        } else {  // Se a fila não está vazia
            lista->ultimo->prox = novo;  // O último nó aponta para o novo nó
        }

         lista->ultimo = novo;  // O novo nó é agora o último da fila
        novo->prox = NULL;     // O novo nó aponta para NULL (final da fila)

        lista->tam++;  // Incrementa o tamanho da fila
    }
}

int main() {
    cabeca lista = {NULL, NULL, 0};  // Inicializa a lista vazia

    // Testa a função enfileira
    enfileira(&lista, 10);
    enfileira(&lista, 20);
    enfileira(&lista, 30);

    // Exibe os elementos da fila
    no *temp = lista.prox;
    while (temp) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }

    printf("NULL\n");

    return 0;
}
