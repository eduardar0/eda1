#include <stdio.h>
#include <stdlib.h>

void exch(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *v, int l, int r) {
    int i = l - 1, j = r, pivo = v[r];

    while (i < j) {
        while (v[++i] < pivo); // Incrementa i até encontrar um elemento >= pivo
        while (pivo < v[--j] && j > l); // Decrementa j até encontrar um elemento <= pivo
        if (i < j) exch(&v[i], &v[j]); // Troca os elementos fora de posição
    }
    exch(&v[i], &v[r]); // Coloca o pivô na posição correta
    return i;
}

void quick_sort(int *v, int l, int r) {
    if (r <= l) return; // Condição de parada
    int p = partition(v, l, r);

    quick_sort(v, l, p - 1); // Ordena a parte esquerda
    quick_sort(v, p + 1, r); // Ordena a parte direita
}

int main() {
    int tam, elem, pag;
    scanf("%d %d %d", &tam, &elem, &pag);

    // Alocação dinâmica para armazenar os IDs dos produtos
    int *v = malloc(sizeof(int) * tam);
    if (!v) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Lê os IDs
    for (int i = 0; i < tam; i++) {
        scanf("%d", &v[i]);
    }

    // Ordena os IDs
    quick_sort(v, 0, tam - 1);

    // Calcula os índices da página
    int start = pag * elem; // Primeiro índice da página
    int end = start + elem; // Último índice da página (não inclusivo)
    if (end > tam) end = tam; // Limita o final ao tamanho do vetor

    // Imprime os IDs da página solicitada
    for (int i = start; i < end; i++) {
        printf("%d\n", v[i]);
    }

    // Libera a memória alocada
    free(v);
    return 0;
}
