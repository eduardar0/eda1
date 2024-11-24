#include <stdio.h>

void insertion_sort(int v[], int l, int r) {
    for (int i = l + 1; i <= r; i++) { //laço que percorre o vetor
        int elem = v[i];  // Elemento a ser inserido
        int j = i - 1;

        // Move os elementos maiores que `elem` para a direita
        while (j >= l && v[j] > elem) {
            v[j + 1] = v[j];
            j--;
        }

        // Insere o elemento na posição correta
        v[j + 1] = elem;
    }
}

int main() {
    int v[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(v) / sizeof(v[0]);

    insertion_sort(v, 0, n - 1);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

    //o(n^2) quadratico 
    //estavel 
    //nao pe inplace 
    //adaptativo 

// void inserction(int v[], int r, int l){
//     for(int i = l+1; i<=r; i++){
//         int elem = v[i];// elemento a ser inserido 
//         int j = i-1;

//         while(j>= l && v[j] > elem){

//             v[j+1] = v[j]; 
//             j--;
//         }
//         v[j + 1] = elem;


//     }
// }