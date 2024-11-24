#include <stdio.h>

// Função recursiva para busca binária
int busca_binaria_recursiva(int v[], int l, int r, int x) {
    if (l >= r) {
        return l;  // Retorna o índice j encontrado
    }

    int meio = (l + r) / 2;


    if (x <= v[meio]) {
        return busca_binaria_recursiva(v, l, meio, x);  // Busca na metade esquerda
    } else {
        return busca_binaria_recursiva(v, meio + 1, r, x);  // Busca na metade direita
    }
}

// a busac binaria trabalha com intervalos fechados ou semiabertos
//essse é semiaberto, por so da o tamanho de r e nao de l 
//Quando dividimos o intervalo, a função decide qual parte (esquerda ou direita) explorar
//ão usamos meio - 1 aqui porque a divisão de intervalos já evita reprocessar índices desnecessários.

int main() {
    int N, M;

    // Leitura de N e M
    scanf("%d %d", &N, &M);
    
    int v[N];
    int consultas[M];
    
    // Leitura do array ordenado
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    
    // Leitura dos números a serem buscados
    for (int i = 0; i < M; i++) {
        scanf("%d", &consultas[i]);
    }
    
    // Processando cada consulta
    for (int i = 0; i < M; i++) {
        int x = consultas[i];
        int posicao = busca_binaria_recursiva(v, 0, N, x);
        printf("%d\n", posicao);
    }
    
    return 0;
}
