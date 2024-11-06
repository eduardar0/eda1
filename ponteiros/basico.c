// 1. Básico com Ponteiros
// Declaração e Atribuição: Crie um ponteiro para um int e atribua a ele o endereço de uma variável int. Exiba o valor da variável usando o ponteiro.
// Modificando Valor via Ponteiro: Crie uma função que receba um ponteiro para int e modifique o valor da variável apontada para o dobro do valor original. 

#include <stdio.h>

void troca(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int main(){
int *p;
int v = 5;
p = &v;
printf("lala %p\n", p);//endereço de memoria
printf("lala %d\n", *p);//valor contido em v

int x = 3;
int y = 9;
troca(&x,&y);
printf("%d %d\n", x, y);//devem ser passados os endereços

int var = 15;
//ponteiros sao utilizados para apontar endereços de memoria 
//consegimos atualizar coteudos desses endereços de forma indireta
int *ptr;
ptr = &var; // ponteiro aponta para o ENDEREÇO da variavel, &&&&&
printf("Conteudo de var= %d\n", var);
printf("Conteudo do endereço apontado por ptr= %d\n", *ptr);
printf("Endereço apontado por ptr= %p\n", ptr);
printf("endereço do ponteiro prt = %p\n", &ptr);
*ptr = 73;
printf("Conteudo do endereço atualizado apontado por ptr= %d\n", *ptr);
    return 0;
}