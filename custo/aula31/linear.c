//exemplos de custos lineares 
#include<stdio.h>

int pesquisa(int x, int n, int v[]){
    int i;//constrante
    for (i=0; i < n  && v[i] != x; i++); //condição pro custo rodar n vezes
    return i; 
}

int soma(long n){//condição pro custo rodar n vezes
    int r =0;
    while(n> 0){
        r+= n%10; //constante
        n/=10; //constante
    }
}

int busca(int n, int *v, int x){

    int i;
    for(i=0; i<n && v[i] != x; i++);
    return i;
    }
    

int fatorial1 ( int n) {
    int fat = 1; //1 pra b

 while ( n > 0) //n ..0 //1 pra a 
 fat *= n-- ; //atribuição e multiplicação 2 pra a

//3 * n + 1



    return fat ; //nao conta o retorno???????????/
}