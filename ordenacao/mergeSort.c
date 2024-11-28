#include<stdio.h> 

// LINEARITMCO 
// O(N LOG N)
//Melhor custo quando a oredenaação é por compararção do valor chave
//metodo dividir e conquistar 
void merge(int *v, int l, int m, int r){
    int i,j,k;
    int n1 = m-l +1;
    //tamanho do subarray esquerdo 
    int n2 = r-m;

    int *L = (int*)malloc(n1* sizeof(int)); //arrays temporarios
    int *R = (int*)malloc(n2* sizeof(int));

    for(i =0; i<n1;i++){
        L[i] = v[l+1];}
    for(j=0; j<n2; j++){
        R[j] = v[m +1 +j];

        }
    //mescla os arrays temporarios em volta de v[l..r]

    i = 0; //indicer incial cdo subarray esquyerdo 
    j =0; //indicer incial cdo subarray direitpo  
    //indice inicial do array mesclado 
    k = l;

    
    while(i< n1 && j<n2){
        if(L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }
        else{
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        v[k] = R[j];
        j++;
        k++;
    }

    while (j<n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(r);

}


void merge_sort1(int *v[], int r, int l){
    if (l>=r) return;

    int m = (l+r)/2; 

    merge_sort1(v, l, m);
    merge_sort1(v, m+1, r);
    merge(v, l, m,r);

}