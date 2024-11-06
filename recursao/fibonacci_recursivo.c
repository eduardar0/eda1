#include<stdio.h>

int fib(int n){
if (n==0 || n ==1) return n;

return fib(n-2) + fib (n-1);
}

int main(){

    int a = fib(4);
    printf("%d\n", a);
}

//primeira condição, n =4
//n == 0 ? nao, n== 1? nao -> fib(4-2) + fib(4-1)
//fib(4-1) = fib(2) = fib(2-2) + fib(2-1) == fib(0) + fib(1) == 0+1 == 1(guarda)
//                                            //condições de parada  
//fib(4-1) == fib(3) == fib(3-2) + fib(3-1) == fib(1) (CP == 1) + fib(2) (1)
//fib(3)=2
//2+1 =3;
//saida:3
