#include <stdio.h>


char *a = "* + 7 * * 4 6 + 8 9 5"; // Expressão de exemplo
int i = 0; // Índice global para percorrer a string

// Função para avaliar a expressão recursivamente
//vai lendo a expressão e toamndo decisões com base no que encontra
//se encontra um numero ela retorna esse numero
//se encontra um operador ela chama a si mesma recursivamente para resolver a expressão

int eval() {
    int x = 0;

    // Ignorar espaços em branco
    while(a[i] == ' ') 
        i++;

    // Se o próximo caractere for um '+', fazer a soma recursiva
    if(a[i] == '+') { 
        i++; 
        return eval() + eval();
    }

    // Se o próximo caractere for um '*', fazer a multiplicação recursiva
    if(a[i] == '*') { 
        i++; 
        return eval() * eval();
    }

    // Caso contrário, trata-se de um número
    //enquanto for número
    //converte um dígito(char) em número(int)
    while(a[i] >= '0' && a[i] <= '9') 
        x = 10 * x + (a[i++] - '0');//tabela ascii
    
    return x; // Retorna o número encontrado
}

int main() {
    printf("Resultado: %d\n", eval()); // Imprime o resultado da avaliação da expressão
    return 0;
}
