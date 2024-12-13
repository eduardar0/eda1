#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;                // Dado armazenado no nó
    struct Node *next;       // Ponteiro para o próximo nó
    struct Node *sublist;    // Ponteiro para uma sublista
} Node;


Node *criarNo(int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->data = valor;
    novo->next = NULL;
    novo->sublist = NULL;
    return novo;
}

void inserirNaListaPrincipal(Node **head, int valor) {
    Node *novo = criarNo(valor);
    novo->next = *head;
    *head = novo;
}

void inserirNaSublista(Node *parent, int valor) {
    if (parent == NULL) return; // Não há sublista para adicionar

    Node *novo = criarNo(valor);
    novo->next = parent->sublist;
    parent->sublist = novo;
}


void inserirNaSublista(Node *parent, int valor) {
    if (parent == NULL) return; // Não há sublista para adicionar

    Node *novo = criarNo(valor);
    novo->next = parent->sublist;
    parent->sublist = novo;
}


void imprimirMultilista(Node *head) {
    while (head != NULL) {
        printf("%d", head->data);

        if (head->sublist != NULL) {
            printf(" -> Sublista: ");
            Node *temp = head->sublist;
            while (temp != NULL) {
                printf("%d ", temp->data);
                temp = temp->next;
            }
        }

        printf("\n");
        head = head->next;
    }
}


int main() {
    Node *head = NULL;

    // Inserindo na lista principal
    inserirNaListaPrincipal(&head, 30);
    inserirNaListaPrincipal(&head, 20);
    inserirNaListaPrincipal(&head, 10);

    // Inserindo em sublistas
    inserirNaSublista(head->next, 21); // Sublista de 20
    inserirNaSublista(head->next, 22); // Sublista de 20

    imprimirMultilista(head);

    return 0;
}


