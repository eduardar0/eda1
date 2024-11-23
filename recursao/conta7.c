#include <stdio.h>

int conta7(const char *str, int n) {
    if (str[n] == '\0') { // Verifica o final da string
        return 0;
    }

    int i = 0;
    if (str[n] == '7') { // Compara se o caractere atual é '7'
        i = 1; // Incrementa o contador se for '7'
    }

    // Soma o resultado atual com a chamada recursiva
    return i + conta7(str, n + 1);
}

int main() {
    char str[20];
    scanf("%s", str); // Lê a string do usuário
    printf("%d\n", conta7(str, 0)); // Chama a função com índice inicial 0
    return 0;
}
