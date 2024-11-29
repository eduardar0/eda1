#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para armazenar informações da sequência
typedef struct {
    int tamanho;
    char caractere;
    int posicao;
} Sequencia;

// Função de comparação para ordenar os resultados
int comparar(const void *a, const void *b) {
    Sequencia *seqA = (Sequencia *)a;
    Sequencia *seqB = (Sequencia *)b;
    
    // Comparar pelo tamanho da sequência (decrescente)
    if (seqB->tamanho != seqA->tamanho) 
        return seqB->tamanho - seqA->tamanho;

    // Manter a ordem original em caso de empate
    return 0;
}

int main() {
    char s[100001];
    scanf("%s", s); // Ler a string

    int n = strlen(s);
    Sequencia resultados[100001];
    int indice = 0;

    int i = 0;
    while (i < n) {
        char atual = s[i];
        int inicio = i;
        int contagem = 0;

        // Contar o tamanho da sequência
        while (i < n && s[i] == atual) {
            contagem++;
            i++;
        }

        // Armazenar a sequência
        resultados[indice].tamanho = contagem;
        resultados[indice].caractere = atual;
        resultados[indice].posicao = inicio;
        indice++;
    }

    // Ordenar as sequências
    qsort(resultados, indice, sizeof(Sequencia), comparar);

    // Imprimir os resultados
    for (int j = 0; j < indice; j++) {
        printf("%d %c %d\n", resultados[j].tamanho, resultados[j].caractere, resultados[j].posicao);
    }

    return 0;
}
