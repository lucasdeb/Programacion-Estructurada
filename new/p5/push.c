#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

int imprimir(t_nodo* pila);
int pop(t_nodo* pila);
void push(t_nodo* pila, int valor);

int main(void){
    t_nodo pila = NULL;

    int d;
    scanf("%d",&d);

    while (d!=0){
        push(&pila,d);
        scanf("%d",&d);
    }
    printf("Popped: %d\n",pop(&pila));
    imprimir(&pila);
}

void push(t_nodo* pila, int valor){
    t_nodo aux = malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->sig = *pila;
    *pila = aux;
}

int pop(t_nodo* pila){
    int valor;
    t_nodo aux = (*pila);
    valor = aux->valor;
    *pila = aux->sig;
    free(aux);
    return valor;
}

int imprimir(t_nodo* pila){
    if((*pila)!=NULL){
        imprimir(&(*pila)->sig);
        printf("%d <%d> prox:<%d>\n",(*pila)->valor, pila, &(*pila)->sig);
    }
    else{
        return 0;
    }
}