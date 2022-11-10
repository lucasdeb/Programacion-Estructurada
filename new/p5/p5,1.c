#include <stdio.h>
#include <stdlib.h>

struct datos{
    char *nombre;
    char *apellido;
    int dni;
};
typedef struct datos d;

struct s_nodo{
    d cont;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void cargarLista(t_nodo* l);

int main(void){
    t_nodo lista = NULL;
    cargarLista(&lista);
    imprimirlista(&lista);
}

void cargarLista(t_nodo* l){
    FILE* arch = fopen("test.txt","r");
    d datos;
    while (!feof(arch)){
        datos->nombre = leerStrDeArch(arch,&(datos->nombre));
        fscanf(arch,"%d,",datos.dni);
        datos->apellido = leerStrDeArch(arch,&(datos->apellido));
        instertarEnListaOrdenado(datos,&l);
    }
}

void leerStrDeArch(FILE* arch, char** arr){
    *arr = malloc(sizeof(char));
    char c, term = ',';
    int i;

    c = fgetc(arch);

    while(!feof(arch)&&c!=term){
        *(arr+i) = c;
        i++;
        *arr = realloc(*arr,sizeof(char)*(i+1));
        c = fgetc(arch);
    }
    *(arr+i) = '\0';
}

void instertarEnListaOrdenado(d datos, t_nodo *lista){

    t_nodo aux = NULL;

    if (*lista==NULL){
        *lista = malloc(sizeof(s_nodo));
        (*lista)->cont = datos;
        (*lista)->sig = NULL;
    }
    else{
        if (datos.dni < (*lista)->cont.dni){
            aux = malloc(sizeof(s_nodo));
            aux->cont = datos;
            aux->sig = (*lista);
            *lista = aux;
        }
        else{
            instertarEnListaOrdenado(datos,&((*lista)->sig))
        }
        
    }
    
}