#include <stdio.h>
#include <stdlib.h>

struct sNodo{
    int valor;
    struct sNodo* sig;
};
typedef struct sNodo* tNodo;

void imprimirListaR(tNodo lista);
void insertarEnListaPrimero(tNodo* nodo, int valor);

void insertarEnListaPrimero(tNodo* nodo, int valor){
    tNodo aux;
    if (*nodo == NULL){
        *nodo = (tNodo)malloc(sizeof(struct sNodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }
    else{
        aux = (tNodo)malloc(sizeof(struct sNodo));
        aux->sig = (*nodo);
        aux->valor = valor;
        (*nodo) = aux;
    }
}

void imprimirListaR(tNodo lista){
    if(lista!=NULL){
        printf("\n valor: %4d dirNodo: <%p>, sirSig: <%p>",(lista)->valor,lista,lista->sig);
        imprimirListaR(lista->sig);
    }
}

int main(void){
    unsigned int n,c;
    tNodo lista = NULL;
    insertarEnListaPrimero(&lista,10);
    insertarEnListaPrimero(&lista,20);
    insertarEnListaPrimero(&lista,30);
    imprimirListaR(lista);
}