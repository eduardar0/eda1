#include<stdio.h>


int main() {
    char T[2] = {'V', 'F'}; // Vetor com 2 elementos: 'V' e 'F'

    // 3º: processa 2^2^2 = 16 instruções
    for (int a = 0; a < 2; a++) {
        // 2º: processa 2^2 = 4 instruções
        for (int b = 0; b < 2; b++) {
            // 1º: processa 2 instruções
            for (int c = 0; c < 2; c++) {
                printf("%c %c %c\n", T[a], T[b], T[c]);
            }
        }
    }

    return 0;
}


int fibonacci(int n) {
    if (n <= 1) return n;        // Caso base
    return fibonacci(n - 1) + fibonacci(n - 2); // Chamadas recursivas
}

