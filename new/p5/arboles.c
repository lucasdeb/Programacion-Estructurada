#include <stdio.h>
#include <stdlib.h>

typedef struct sNodoBin{
    int valor;
    struct sNodoBin* izq;
    struct sNodoBin* der;
} *tNodoBin;

void insertar(tNodoBin* arbol, int valor);
void post(tNodoBin arbol);

int main(void){
    tNodoBin arbol = NULL;
    insertar(&arbol,8);
    insertar(&arbol,3);
    insertar(&arbol,5);
    insertar(&arbol,18);
    insertar(&arbol,12);
    insertar(&arbol,2);
    insertar(&arbol,4);
    printf("%d\n",arbol);
    post(arbol);
}

void insertar(tNodoBin* arbol, int valor){
    if ((*arbol) == NULL){
        (*arbol) = malloc(sizeof(struct sNodoBin));
        (*arbol)->valor = valor;
        (*arbol)->izq = NULL;
        (*arbol)->der = NULL;
    }
    else{
        if (valor < (*arbol)->valor){
            insertar(&(*arbol)->izq,valor);
        }
        else{
            insertar(&(*arbol)->der,valor);
        }
    }
}

//para imprimir el arbol en orden (ascendente o descendente)
//para ascendente seria arbol->izq y despues arbol->der

void post(tNodoBin arbol){
    if(arbol!=NULL){
        post(arbol->izq);
        printf("IZQ:%d(%d) VAL:(%d)%d DER:%d(%d)\n",*(arbol->izq),arbol->izq,arbol->valor,&(arbol->valor),*(arbol->der),arbol->der);
        post(arbol->der);
    }
}