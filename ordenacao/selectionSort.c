#include<stdio.h> 
void selection_sort(int v[], int l, int r){
    int menor; //m variavel auxiliar

    for(int i = l; i<r; i++){
        menor = i;
        for(int j = i+1; j<r; j++){
            if(v[j]<v[menor]){
                menor = j; //salva a posição do menor
            }
            if(i!= v[menor]){
                exch(v[i], v[menor]);

            }
        }
    }

}
void exch(int *a, int*b){
    int temp; 
    temp = a; 
    *a = b;
    *b = temp;
} //troca


// quadratico (o(n^2))
//nao é adaptativo, pois a cada interação cada elemento é comparado somente com o menor 
//não é estável v(nao mantem a ordem relativa, tem trocas com saltos, nao mantem a ordem)
//nao é in-place, nao utiliza memoruia extra significativa 