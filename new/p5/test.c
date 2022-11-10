#include <stdio.h>
#include <stdlib.h>

struct contenido{
    int age;
    char* name;
};
typedef struct contenido cont;

struct s_nodo{
    cont valor;
    struct s_nodo *sig;
};
typedef struct s_nodo* t_nodo;

void insertarEnListaOrd(t_nodo *nodo, cont datos);
void escribirArrDin(FILE* arch, char** arr);
void imprimirListaR(t_nodo lista);
void cargarLista(t_nodo *lista);
void insertarUltimo(t_nodo *nodo,cont datos);
void insertarPrimero(t_nodo *nodo, cont datos);

int main(void){
    t_nodo lista = NULL;
    cargarLista(&lista);
    imprimirListaR(lista);
}

void cargarLista(t_nodo *nodo){
    FILE* arch = fopen("test.txt","r");
    cont datos;
    while(!feof(arch)){
        escribirArrDin(arch,&(datos.name));
        fscanf(arch,"%d\n",&(datos.age));
        insertarEnListaOrd(nodo,datos);
        //insertarUltimo(nodo,datos);
        //insertarPrimero(nodo,datos);
    }
    fclose(arch);
}

void insertarPrimero(t_nodo *nodo, cont datos){
    t_nodo aux = NULL;

    if (*nodo == NULL){
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->valor = datos;
        (*nodo)->sig = NULL;
    }
    else{
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->valor = datos;
        aux->sig = *nodo;
        *nodo = aux;
    }
    
}

void insertarUltimo(t_nodo *nodo,cont datos){
    if (*nodo == NULL){
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->valor = datos;
        (*nodo)->sig = NULL;
    }
    else{
        insertarUltimo(&(*nodo)->sig,datos);
    }
    
}

void insertarEnListaOrd(t_nodo *nodo, cont datos){
    t_nodo aux = NULL;

    if((*nodo) == NULL){
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->valor = datos;
        (*nodo)->sig = NULL;
    }
    else{
        if (datos.age > (*nodo)->valor.age){
            aux = (t_nodo)malloc(sizeof(struct s_nodo));
            aux->valor = datos;
            aux->sig = (*nodo);
            (*nodo) = aux;
        }
        else{
            insertarEnListaOrd(&(*nodo)->sig, datos);
        }
    }
}

void escribirArrDin(FILE* arch, char** arr){
    char c;
    int i=0;
    *arr = malloc(sizeof(char));

    c = fgetc(arch);

    while(!feof(arch) && c!=','){
        *((*arr)+i) = c;
        i++;
        *arr = realloc(*arr,sizeof(char)*(i+1));
        c = fgetc(arch);
    }
    *((*arr)+i) = '\0';
}

void imprimirListaR(t_nodo lista){
    if (lista!= NULL){
        imprimirListaR(lista->sig);
        printf("%-20s %-5d\n",lista->valor.name,lista->valor.age);
    }
}