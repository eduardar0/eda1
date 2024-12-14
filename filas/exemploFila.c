#include <stdio.h>

#define N 7

int fila[N];
int p, u;

void criar_fila() {
    p = u = 0;
}

int main() {
    criar_fila();
    printf("Fila criada. p = %d, u = %d\n", p, u);
    return 0;
}
