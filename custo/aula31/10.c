#include <stdio.h>

int fat(int n) {
    if (n == 0) 
        return 1;
    return n * fat(n - 1);
}

int main() {
    int x = fat(3);
    printf("Fatorial de 3 é: %d\n", x);
    return 0;
}
