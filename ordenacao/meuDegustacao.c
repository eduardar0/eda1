#include<stdio.h>
#include<string.h>


typedef struct 
{
    int tamanho; 
    char caractere;
    int posicao;
}Sequencia;

void exch(void *a, void *b){
    Sequencia *x = (Sequencia *) a;
    Sequencia *y = (Sequencia*) b;
    Sequencia temp = *x;
    *x = *y;
    *y = temp;
}


int partition(Sequencia *v, int l, int r){
    int i = l-1, j = r ; 
    Sequencia pivo = v[r];

    while(1){
        while(v[++i].tamanho<pivo.tamanho && i < r); //se i for iguala r acabgou o vetor 
        // Move i para a direita até encontrar um valor maior que o pivô
        while(v[--j].tamanho > pivo.tamanho && j>l);
        // Move j para a esquerda até encontrar um valor menor que o pivô

    if(i>=j) break;
    exch(&v[i], &v[j]);

    } 
    exch(&v[i], &v[r]); //coloca o pivo ond deve estar 
    return i;
}

void quick_sort(Sequencia *v, int l, int r){
    if(l>=r) return; 

    int p = partition(v, r, l); 
    quick_sort(v, l, p-1);
    quick_sort(v, p+1, r); 
}

int main(){
    char s[10000001];
    scanf("%s", s); //le a string do porgrama

    int n = strlen(s); //vai dar o r pro quick_sort

    Sequencia resultados[1000001]; //vetor para armazenar os resultados das sequencias

    int indice = 0; // tipo o l???

    int i =0; 

    while(i<n){ //i for menor que o tamanyho da string 
    char atual = s[i];
    int inicio = i; 
    int contagem = 0; 

    while(i<n && s[i] == atual){
        contagem ++; 
        i++;
    }

    //armazenar a sequencia 
    resultados[indice].posicao = inicio; 
    resultados[indice].caractere = atual;
    resultados[indice].tamanho = contagem; 

    indice++;

    }


    quick_sort(resultados, 0, indice-1); // inndice o tamanho do vetor passado da struct 
    
    //imprimir os resultados ordenados 
    for(int j =0; j<indice; j++){
        printf("%d %c %d\n", resultados[j].tamanho, resultados[j].caractere, resultados[j].posicao);
    }








    return 0; 

}