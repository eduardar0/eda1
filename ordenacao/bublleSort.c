#include<stdio.h>

void bublle_sort(int v[], int l, int r){
    int swap; //indentificar reordenações
    for(int j = l; j<r; j++){
        if(v[j] > v[j+1]){
            exch(v[j], v[j+1]); //flutue
            swap = 1; //reordenação  
        }

    }
    r--; //diminui o tamanho do topo para parar as cpomparaçõs a parttir do maior elemnto
}

//estavel 
// nao é inplace 
//pior que o select sort 