typedef char Item; 
typedef struct{

    Item *dado;
    int topo;
} pilha;

pilha *criar(int maxN){
    pilha *p=  malloc(sizeof(pilha));
    p->dado = malloc(maxN*malloc(sizeof(Item)));
    p->topo =0;
    return p;
}

void empilha(pilha *p, Item y){
    p->dado[p->topo++] = y;
}

Item desempilha(pilha *p){
    return p->dado[--p->topo];
}

int vazia(pilha *p){
    return p->topo ==  0;
}

Item espia(pilha *p){
    return p->dado[p->topo-1];
}
