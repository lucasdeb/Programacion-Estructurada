#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *nombre;
    //int notas[5];
    //char estado;
}t_dato;

struct s_nodo{
    t_dato cont;
    struct s_nodo *sig;
};
typedef struct s_nodo* t_nodo;

void insertarUltimo(t_nodo *nodo, t_dato datos);
void cargarlistaDeArch(const char *nomArch, t_nodo *nodo);
void escribirArrNombre(FILE* arch, char **arr);
void imprimirLista(t_nodo *lista);
//char cargarArrNotas(FILE* arch, int arri[5]);

int main(void){
    t_nodo lista = NULL;
    cargarlistaDeArch("test.txt",&lista);
    imprimirLista(&lista);
}

void cargarlistaDeArch(const char *nomArch, t_nodo *nodo){
    FILE* arch = fopen(nomArch,"r");
    t_dato datos;

    while(!feof(arch)){
        escribirArrNombre(arch, &(datos.nombre));
        //datos.estado = cargarArrNotas(arch, datos.notas);
        insertarUltimo(nodo, datos);
    }
    fclose(arch);
}

void escribirArrNombre(FILE* arch, char **arr){
    char c;
    int i=0;
    *arr = malloc(sizeof(char));

    c = fgetc(arch);

    while(!feof(arch) && c!=','){
        *((*arr)+i) = c;
        i++;
        (*arr) = realloc((*arr),sizeof(char)*(i+1));
        c = fgetc(arch);
    }
    *(*(arr)+i) = '\0';
}
/*
char cargarArrNotas(FILE* arch, int arri[5]){
    int cont=0;
    fscanf(arch,"%d,%d,%d,%d,-1\n",arri[0],arri[1],arri[2],arri[3]);
    for (int i = 0; i < 4; i++){
        if(arri[i]>=7){
            cont++;
        }
    }
    if (cont>=3){
        return 'A';
    }
    else{
        return 'A';
    }
}
*/

void insertarUltimo(t_nodo *nodo, t_dato datos){

    if(*nodo == NULL){
        (*nodo) = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->cont = datos;
        (*nodo)->sig = NULL;
    }
    else{
        insertarUltimo(&(*nodo)->sig,datos);
    }
}

void imprimirLista(t_nodo *lista){
    if(*lista!=NULL){
        printf("%s\n",(*lista)->cont.nombre);
        imprimirLista(&(*lista)->sig);
    }
}