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

        while (j > l && ((v[--j].S > pivo.S) || (v[j].S == pivo.S && v[j].N > pivo.N)));

        if(i<j) exch(&v[i],&v[j]);
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
    int k;
    scanf("%d", &k);

    int i = 0;
    Semente *v = malloc(1000 * sizeof(Semente)); // Ajuste no tamanho da alocação

    if (v == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }

    // Lê as sementes até o fim do arquivo (EOF)
    while (scanf("%lld %d", &v[i].S, &v[i].N) != EOF) {
        i++;
        if (i % 1000 == 0) {  // Realoque mais memória conforme necessário
            v = realloc(v, (i + 1000) * sizeof(Semente));
            if (v == NULL) {
                fprintf(stderr, "Erro de alocação de memória.\n");
                return 1;
            }
        }
    }

    int r = i;

    // Ordenação das sementes
    quick_sort(v, 0, r-1);

    // Imprime as k sementes com menor código
    for (int i = 0; i < k; i++) {
        printf("\nSemente com menor código: S = %lld, N = %d\n", v[i].S, v[i].N);
    }

    free(v);

    return 0;
}
