#include <stdio.h>

//funções que chamam elas oproprias ate achar a condição de parada
//recursivo 
int fat(int n) {
    if (n == 0) 
        return 1; //condição de parada
    return n * fat(n - 1);
}

int main() {
    int x = fat(4);
    printf("Fatorial de 3 é: %d\n", x);
    return 0;
}

//1° execução: n * fat(n-1);
// n =3
// 3* fat(2)
//    n = 2;
//       2* fat(1)
//         n = 1;
//          1 *fat(0)
//            n = 0; // CONDIÇÃO DE PARADA- return 1;

//AGORA COMEÇA O PROCESSO DE DESEMPILHAMENTO 

//fat(0) recebe 1, que va multipilcar com 1 do fat(1)
//entap fat(1) recebe 1, que vai multiplicar com 2 de fat(2)
//2*1 = 2
//fat(2) vai retornar 2, que vai multiplicar com 3 do fat(3)
//3*2 ==6; o que acaba a recursao.