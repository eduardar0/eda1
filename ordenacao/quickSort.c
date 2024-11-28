#include<stdio.h>

void exch(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *v, int r, int l) {
    int i = l - 1, j = r, pivo = v[r];

    while (i < j) {
        while (v[++i] < pivo);
        while (v[--j] > pivo && j > l);
        if (i < j) 
            exch(&v[i], &v[j]);
    }
    exch(&v[i], &v[r]); // Coloca o pivô na posição correta
    return i;           // Retorna o índice do pivô
}

void quick_sort(int *v, int l, int r) {
    if (l >= r) return; // Condição de base: intervalo inválido

    int p = partition(v, r, l); // Particiona e obtém o índice do pivô

    quick_sort(v, l, p - 1); // Ordena a subparte esquerda
    quick_sort(v, p + 1, r); // Ordena a subparte direita
}

int main() {
    int v[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    quick_sort(v, 0, n - 1);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
