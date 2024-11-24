#include<stdio.h>

void shell_sort(int v[], int r, int l){
int h = 1, elem, u,j;
//calcula o maio intervalo inical usando a formula h = h*3+1
while (h<(r-l+1)/3){
    h =3 *h +1;//h 
}
while(h>=1){
     //enquanto o intervalo for mai0or ou igual a 1
    for(int i = l+h;i<= r; i++){
        //pwercorre o vetor começando do indice l +h
        for(int j = i; j>=l+h; j-=h){
            v[j] = v[j-h];

        }
        v[j] = elem;
    } 
    h = h/3; //reduz o intervalo para o proximo caso 
}

}