#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long S;  // código da semente
    int N;        // nota da semente
} Semente;
void exch(void *a, void *b){
    Semente *x = (Semente *) a;
    Semente *y = (Semente *) b;
    Semente temp = *x; 
    *x = *y; 
    *y = temp;
}
int partition(Semente *v, int l, int r){
    int i = l-1, j = r;
    Semente pivo = v[r];

    while(i<j){
        while ((v[++i].S < pivo.S) || (v[i].S == pivo.S && v[i].N < pivo.N));

        // Retrocede o índice 'j' enquanto os elementos estão na ordem correta
        while (j > l && ((v[--j].S > pivo.S) || (v[j].S == pivo.S && v[j].N > pivo.N)));

        if(i<j) exch(&v[i],&v[j]); 
        //desempate

        // while (j > l && ((v[--j].S > pivo.S) || (v[j].S == pivo.S && v[j].N > pivo.N)));

    }
    exch(&v[i], &v[r]); 
    return i; 
}

void quick_sort(Semente *v, int l, int r){
    if(r<=l) return; 

    int p = partition(v, l, r);
    quick_sort(v, l, p-1);
    quick_sort(v, p+1, r);

}

int main() {
    Semente v[] = {{10, 90}, {20, 85}, {15, 88}, {5, 80}, {30, 80}};

    int r =sizeof(v) / sizeof(v[0]);

    quick_sort(v, 0, r-1); 

    int k =4;

    for(int i =0; i<k; i++){
        printf("Semente com menor código: S = %lld, N = %d\n", v[i].S, v[i].N);
    }


    return 0;
} 