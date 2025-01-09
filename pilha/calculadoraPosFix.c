#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Estrutura do nó da pilha
typedef struct No {
    int dado;
    struct No *prox;
} No;

// Estrutura da lista/pilha
typedef struct head {
    No *topo;
    int num_itens;
} head;

// Função para criar a lista encadeada (pilha)
head* criar_lista() {
    head *lista = (head*)malloc(sizeof(head));
    lista->topo = NULL;
    lista->num_itens = 0;
    return lista;
}

// Função para criar um novo nó
No* criar_no(int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo) {
        novoNo->dado = valor;
        novoNo->prox = NULL;
    }
    return novoNo;
}

// Função para verificar se a pilha está vazia
int vazia(head *lista) {
    return lista->topo == NULL;
}

// Função para empilhar um valor
void empilha(head *lista, int valor) {
    No *novoNo = criar_no(valor);
    if (novoNo) {
        novoNo->prox = lista->topo;
        lista->topo = novoNo;
        lista->num_itens++;
    }
}

// Função para desempilhar um valor
int desempilha(head *lista) {
    if (vazia(lista)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    
    No *temp = lista->topo;
    int valor = temp->dado;
    lista->topo = temp->prox;
    free(temp);
    lista->num_itens--;
    return valor;
}

// Função principal
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <expressao posfixada>\n", argv[0]);
        return 1;
    }

    char *a = argv[1];
    head *pilha = criar_lista();

    for (int i = 0; a[i] != '\0'; i++) {
        // Se for um operador '+'
        if (a[i] == '+') {
            empilha(pilha, desempilha(pilha) + desempilha(pilha));
        }
        // Se for um operador '*'
        else if (a[i] == '*') {
            empilha(pilha, desempilha(pilha) * desempilha(pilha));
        }
        // Se for um número, empilha
        else if (isdigit(a[i])) {
            empilha(pilha, 0);
            while (isdigit(a[i])) {
                empilha(pilha, 10 * desempilha(pilha) + (a[i++] - '0'));
            }
            i--; // Corrige o incremento extra do while
        }
    }

    printf("Resultado: %d\n", desempilha(pilha));
    return 0;
}
