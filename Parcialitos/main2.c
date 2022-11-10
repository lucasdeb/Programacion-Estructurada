#include <stdio.h>
#include <string.h>

struct s_dato{
    char* alumno;
    int nota[3];
    float prom;
};
typedef struct s_dato t_dato;

struct s_nodo{
    t_dato dato;
    struct s_nodo* sig;
};
typedef struct s_nodo t_nodo;

void cargarLista(t_nodo* ls, char* nomA, char* nomB){
    t_dato dato = {{0}};
    char auxC;
    float auxF;

    FILE* archA = fopen(nomA,"r");
    FILE* archN = fopen(nomB,"r");

    if (archA!=NULL && archN!=NULL){
        while(!feof(archA)&&!feof(archN)){
            for(int i=0;auxC=fgetc(archA)!='\n'&& auxC!=EOF){
                dato.alumno[i] = auxC;
            }
            dato.alumno[i] = '\0';

            fscanf(archN,"%d,%d,%d",&(dato.nota[0]), &(dato.nota[1]), &(dato.nota[2]));
            dato.nota[3]=-1;

            auxF = 0;
            for(i=0;dato.nota!=-1;i++){
                auxF = auxF+dato.nota[i];
            }

            dato.prom = auxF/i;
            agregarEnLista(ls,dato);
        }   
    }
}

t_nodo crearNodo(t_dato dato, t_nodo sig){
    t_nodo nodo = (t_nodo)malloc(sizeof(struct s_nodo));

    nodo->dato = dato;
    nodo->sig = sig;

    return nodo;
}

void agregarEnLista(t_nodo* nodo, t_dato dato){
    if(*nodo == NULL){
        *nodo = crearNodo(dato,NULL);
    }
    else{
        if(strcmp(*(nodo)->dato.alumno,dato.alumno)>0){
            *nodo = crearNodo(dato,*nodo);
        }
        else{
            agregarEnLista(&((*nodo)->sig),dato);
        }
    }
}

