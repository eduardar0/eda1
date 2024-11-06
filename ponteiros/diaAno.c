#include<stdio.h>


void verificaBissexto(int *ano, int *bissexto){
    if ((*ano % 400 == 0) || (*ano % 4 == 0 && *ano % 100 != 0)){
        *bissexto = 1;
        }
        else{
        *bissexto = 0;
        }
}

void diaMes(int *diaNumero, int *ano, int *mes, int *dia){

    int diasMeses[] = {31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};//quanros dias tem cada mes
    int bissexto = 0;//verificação do ano bissexto
    verificaBissexto(ano, &bissexto);//..?????????????
    if(bissexto){
        diasMeses[1]= 29; // ajusta fevereiro para 29 dias
    }

    *mes = 0; // é iniciado com zero para começar do primeiro mês do ano, janeiros no caso
    //foito para começar a contagem no array diasMeses

    while (*diaNumero> diasMeses[*mes]){
        *diaNumero -= diasMeses[*mes];//subtrai numero de dias dos dias dos mes, ate o numeoro de dias do ano ficar menor que
        //o numero de dias de um mês, achando assim, o numero exato do dia;
        (*mes)++;//se nao achar passa pro proximo mês
    }

    *dia = *diaNumero; // acha o numero do dia
    (*mes++); // inrementa um pois os meses nao começam do zero igual o array


}

// Função para validar a entrada
int validaEntrada(int *diaAno, int *ano) {
    int bissexto = 0;
    verificaBissexto(ano, &bissexto);// acho que é por que 
    //a entrada de verifica bissexto ja é ponteiro, ai tem que paasr normal
    int limiteDias = bissexto ? 366 : 365; // nao conheço ? em C
    // ele questiona a condiçao, se bissexto, tem 366, se nao 365

    // Verifica se o dia do ano está dentro do limite para o ano fornecido
    if (*diaAno < 1 || *diaAno > limiteDias) {
        return 0;  // Entrada inválida
    }
    return 1;  // Entrada válida
}


int main(){

    int d;
    int a;
    scanf("%d %d", &d, &a);
    

    if(!validaEntrada(&d, &a)){
        printf("Entradas Invalidas");
        return 0;
    }

    int dia, mes; // armazernar o dia e o mes 

    diaMes(&d, &a, &mes, &dia);

printf("%02d/%02d/%04d\n", dia, mes, a);



    return 0;
}