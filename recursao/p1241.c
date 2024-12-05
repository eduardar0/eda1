#include<stdio.h>

void funcao(){
    char str[101];
    int cmd;
    scanf("%d", &cmd);

    if(cmd ==1){
        scanf("%[^\n]", str);
        funcao();
        printf("%s\n", str);
        funcao(); 
    }
}

int main(){
    funcao();
}