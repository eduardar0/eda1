#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar o mapa (hash table)
typedef struct {
    int key;     // Número
    int value;   // Posição
} HashNode;

typedef struct {
    HashNode *data;  // Vetor para armazenar pares (chave, valor)
    int size;        // Tamanho do mapa
} HashMap;

// Funções para lidar com o mapa
HashMap* createHashMap(int size) {
    HashMap *map = malloc(sizeof(HashMap));
    map->data = malloc(sizeof(HashNode) * size);
    for (int i = 0; i < size; i++) {
        map->data[i].key = 0;
        map->data[i].value = -1;
    }
    map->size = size;
    return map;
}

int hash(int key, int size) {
    return abs(key) % size;
}

void insert(HashMap *map, int key, int value) {
    int idx = hash(key, map->size);
    while (map->data[idx].value != -1 && map->data[idx].key != key) {
        idx = (idx + 1) % map->size;  // Resolução de colisão por linear probing
    }
    map->data[idx].key = key;
    map->data[idx].value = value;
}

int get(HashMap *map, int key) {
    int idx = hash(key, map->size);
    while (map->data[idx].value != -1) {
        if (map->data[idx].key == key) {
            return map->data[idx].value;
        }
        idx = (idx + 1) % map->size;  // Continua buscando
    }
    return -1;  // Não encontrado
}

void freeHashMap(HashMap *map) {
    free(map->data);
    free(map);
}

// Programa principal
int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Criando o hash map
    HashMap *map = createHashMap(2 * N);  // Tamanho maior para reduzir colisões

    // Lendo os números do conjunto e inserindo no mapa
    for (int i = 1; i <= N; i++) {
        int num;
        scanf("%d", &num);
        if (get(map, num) == -1) {  // Armazena apenas a primeira ocorrência
            insert(map, num, i);
        }
    }

    // Lendo os números a serem buscados e imprimindo os resultados
    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        printf("%d\n", get(map, num));
    }

    // Liberando a memória
    freeHashMap(map);

    return 0;
}
