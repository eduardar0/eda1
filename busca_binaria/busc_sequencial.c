//tratta-se de recuperação de informções a partir de dados previamente armazenados
//as informações são divididas em registros que possuem chaves
//chaves de indetificação sao usasdas nas buscas
//o metodo de pesquisa mais simples é o de busca sequencial:
   /*a poartir do primeiro registro, procura sequencialmente ate encontar a chave procurada */
   //algoritmo LINEAR
//listas encadeadas: complexiedade: inserção e remoção: CONSTANTES
//BUSCA: linear

//PARA VETORES NAO ORDENADOS: inserção e remoção: o(1) - constante
//busca: o(n) - linear

//PARA VETORES ORDENADOS: inserção e remoção: o(log n)
//busca: linear o(n)

int busca_sequencial(int vetor[], int tamanho, int elemento){
    for(int i =0; i<tamanho; i++){
        if(vetor[i] == elemento){
            return i;
        }

    }
    return -1; //se o elemento não for encontrado
}

