//geralmente usamos ponteiros de ponteiros para modififcar a cabeca da lista dentro de funções
//adc ou remover elementos
//evitar retrornar valores ao manipular listas


#include <stdio.h>
#include <stdlib.h>

// Definindo o nó da lista
#include <stdio.h>
#include <stdlib.h>

// Definindo o nó da lista
struct Node {
    int data;              // O valor do nó
    struct Node *next;     // Ponteiro para o próximo nó
};



//inserir um nó no inicio da lista 

// Função para adicionar um nó no início da lista
void addAtHead(struct Node **head, int value) {
    // Cria um novo nó
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    newNode->data = value;       // Define o valor do nó
    newNode->next = *head;       // Faz o próximo do novo nó apontar para o antigo head
    *head = newNode;             // Atualiza o ponteiro head para o novo nó
}

int main() {
    struct Node *head = NULL;    // Inicializa a lista como vazia

    addAtHead(&head, 10);        // Adiciona 10 no início
    addAtHead(&head, 20);        // Adiciona 20 no início
    addAtHead(&head, 30);        // Adiciona 30 no início

    // Imprime a lista
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
