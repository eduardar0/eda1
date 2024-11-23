//metoo eficiente 
//para conjunto de dados ordenados
//primeria comparação: elemnto do meio
//divisão e conquista
//divide o vetor no meeio

#define key(A) (A.chave) //abreviuação para acessar a chave de um item 
//em vez de digitar item.chave toda vez que quiser a cessar a chave de um item, pode usar key(item)
typedef int Key; //typrdef cira um apelido para tipos existentes, o tipo int foi apelidado como key.
//sempre que usar key no codigo, sera tratado como int

struct data{

    Key chave;
    char info[100];

};  //struct chamada item

typedef struct data Item; //redefine o nome da struct data para item

int busca_binaria(Item *v, int l, int r, Key k){ // v é onde os itns estão armazenados
//l é o indice inicial a esquersda e r final a direita
//key K a chave que está procureando 

if(l>r) return -1;  //condição de parada, indice da esquerda é maior que o da direita, quer dizer que o vetor acabou 

int m = (l+r) / 2; //acha o meio repetidas vezes 
if(k  == key(v[m])) return m; 
//se v.chave[m] == k (chave que estamos procurando ), retorna m 

if(k<key(v[m])){
//se k for menor, então a chave está a direita 
return busca_binaria(v, l, m-1, k);
//no lugar do r, vai entrar o meio -1...
//repete recursivamente ate achjar a chave k
}

return busca_binaria(v, m+1, r, k);

}

//complexidade: 
//menlhor caso: k é o meio (primeiro elemento procurado: o(1) - constante
//caso medio e pior caso: o(log n)
//vai divido pra sempre com o divisior sendo exponencialmente aumentado na base 2 pelo indice da arvore
// ex: priemeira divisão: n/2^1
// segunda: n/2^2 
// terceira: n^3 
// ...
// f(n/ 2^ k)   