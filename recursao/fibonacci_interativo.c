#include <stdio.h> 

//a interação acontece quando usamos loops for/while para repetir uma tarfa 
//varias vezes
//ex: fibonacci
int main(){

    int n=4; 
    int fn, fn1, fn2;
    fn2 = 0; //f(0)
    fn1 =1; //f(1)
    fn = n; // f(n) para n = 0 ou 1;

    for (int i =2; i<=n; i++){
        fn = fn2 + fn1;
    //F(n-1) e F(n-2) para a próxima iteração
        fn2 = fn1; //próximo F(n-2) = atual F(n-1)
        fn1 = fn; //próximo F(n-1) = atual F(n)

    }

    printf("%d\n", fn);
    return 0; 
}