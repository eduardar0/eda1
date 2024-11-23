#include <stdio.h>

void inverte(int i, int v[], int tam){
    if(i<tam){
        int j = v[i];
        inverte(i+1, v, tam);
        v[j] = i;
        for(int p =0; p<tam; p++){
            printf("%d ", v[p]);
        printf("\n");
        }
    }
}
void inverte(int i, int v[], int tam){
    if(i<tam){
        int j = v[i];
        inverte(i+1, v, tam);
        v[tam] = i;
        for(int p =0; p<tam; p++){
            printf("%d ", v[p]);
        printf("\n");
        }
    }
}