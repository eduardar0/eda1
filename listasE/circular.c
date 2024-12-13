#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void inserirFim(Node **head, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->data = valor;

    if (*head == NULL) {
        *head = novo;
        novo->next = novo; // Aponta para si mesmo
        return;
    }

    Node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = novo;
    novo->next = *head;
}

void imprimirLista(Node *head) {
    if (head == NULL) return;

    Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(volta ao início)\n");
}

int main() {
    Node *head = NULL;

    inserirFim(&head, 10);
    inserirFim(&head, 20);
    inserirFim(&head, 30);

    imprimirLista(head);

    return 0;
}
