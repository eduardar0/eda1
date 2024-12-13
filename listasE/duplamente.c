#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

void inserirInicio(Node **head, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->data = valor;
    novo->prev = NULL;
    novo->next = *head;

    if (*head != NULL) {
        (*head)->prev = novo;
    }
    *head = novo;
}

void imprimirLista(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    inserirInicio(&head, 10);
    inserirInicio(&head, 20);
    inserirInicio(&head, 30);

    imprimirLista(head);

    return 0;
}
