#include <stdio.h>

// Função para inverter o vetor recursivamente
void inverte(int i, int v[], int tam) {
    if (i < tam / 2) {
        // Troca o elemento v[i] com v[tam - i - 1]
        int temp = v[i];
        v[i] = v[tam - i - 1];
        v[tam - i - 1] = temp;

        // Chamada recursiva
        inverte(i + 1, v, tam);
    }
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    int tam = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    inverte(0, v, tam);

    printf("Vetor invertido: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
