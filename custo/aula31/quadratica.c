#include<stdio.h>

void ordenacao(int v[], int n) {
    for (int i = 1; i < n; i++) {          // Inicia a partir do segundo elemento
        for (int j = i; j > 0 && v[j] < v[j - 1]; j--) { // Compara com os antecessores
            troca(v[j], v[j - 1]);         // Troca os elementos
        }
    }
}
