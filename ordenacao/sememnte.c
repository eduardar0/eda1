#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long S;  // código da semente
    int N;        // nota da semente
} Semente;

// Função de comparação para o heap: menor nota primeiro, se empatar, menor código
int compare(const void *a, const void *b) {
    Semente *s1 = (Semente*)a;
    Semente *s2 = (Semente*)b;

    // Se a nota for diferente, ordena pela nota
    if (s1->N != s2->N)
        return s1->N - s2->N;
    // Caso contrário, ordena pelo código da semente
    return s1->S - s2->S;
}

int main() {
    int k;
    scanf("%d", &k);

    // Definindo a capacidade máxima do vetor de sementes
    Semente *seeds = malloc(k * sizeof(Semente));
    if (seeds == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    int count = 0;

    while (1) {
        Semente s;
        int result = scanf("%lld %d", &s.S, &s.N);
        if (result == EOF) break; // Chegou ao final dos dados de entrada

        if (count < k) {
            seeds[count++] = s;
            // Quando o número de sementes for menor que k, não precisa fazer mais nada
        } else {
            // Se o número de sementes for k, precisamos verificar a semente atual
            // Inserir a nova semente apenas se for melhor do que a pior no heap
            if (s.N < seeds[k-1].N || (s.N == seeds[k-1].N && s.S < seeds[k-1].S)) {
                seeds[k-1] = s;
            }
        }

        // Ordena o array após cada inserção
        qsort(seeds, count < k ? count : k, sizeof(Semente), compare);
    }

    // Ordena pela semente (código) antes de imprimir
    qsort(seeds, k, sizeof(Semente), compare);

    // Imprimir as k melhores sementes
    for (int i = 0; i < k; i++) {
        printf("%lld %d\n", seeds[i].S, seeds[i].N);
    }

    // Libera a memória alocada
    free(seeds);

    return 0;
}
 