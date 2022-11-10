#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sFecha{//12
    int dd, mm, aaaa;
};
typedef struct sFecha tFecha;

struct sContent{
    int dni;
    char* apellido;
    char* nombre;
    tFecha fechaNac;
};
typedef struct sContent tContent;

struct sNodo{
    tContent content;
    struct sNodo* sig;
};
typedef struct sNodo* tNodo;

void insertarEnListaultimo(tNodo* Content);
void insertarEnListaOrdenado (tNodo* nodo, tContent contenido, int nCampo, int Iasc);
void imprimirListaR(tNodo);
int escribirArchDesdeLista(char*, tNodo);
int cargarListaOrdenadaDesdeArch(tNodo* lista, char* archNom, int Campo, int asc);
int criterioOrden(tContent, tContent, int Campo, int asc);
void leerCadDeArch(FILE*, char**, char) ;
void ordenarLista(tNodo, int Campo, int asc);
void ordenarElemento (tNodo nodo, tNodo lista, int nCampo, int asc);

int main(){
    tNodo lista = NULL;
    printf ("Cargar la lista insertando ordenado por un campo, desde la fuente de un archivo\n");
    cargarLista0rdenadaDesdeArch(&lista, "arch.txt", 2, 0);
    imprimirListaR(lista);
    printf("\n");
    printf("Cambiar el orden de la lista, dejandola ordenada por otro campo\n");
    ordenarLista(lista ,1,1);
    imprimirListaR(lista);
    return 0;
}

int escribirArchDesdeLista(char* nomArch, tNodo lista){
    FILE* arch = fopen (nomArch, "W") ;
    if (arch==NULL){
        return -1;
    }

    tContent auxCont;

    while(lista!=NULL){
        auxCont = lista->content;
        fprintf(arch,"%s,", auxCont.apellido);
        fprintf(arch,"%s,", auxCont.nombre) ;
        fprintf(arch, "%d", auxCont.fechaNac.aaaa);
        fprintf(arch,"%d" , auxCont.fechaNac.mm) ;
        fprintf(arch,"%d\n",auxCont.fechaNac.dd);
        lista = lista->sig;
    }
    fclose(arch);
    return 0;
}

int cargarListaOrdenadaDesdeArch(tNodo* lista, char* archNom, int nCampo, int asc){
    FILE* arch = fopen (archNom, "r");
    if (arch==NULL) {
        return -1;
    }
    tContent auxCont={0, NULL, NULL, {0, 0, 0}};
    int auxI;

    while(!feof(arch)){
        fscanf(arch,"%d,",&(auxCont.dni));
        leerCadDeArch(arch, &(auxCont.apellido),',');
        leerCadDeArch(arch,&(auxCont.nombre),',');
        fscanf(arch,"%d\n",&auxI);
        auxCont.fechaNac.dd=auxI%100;
        auxCont.fechaNac.mm=(auxI/100)%100;
        auxCont.fechaNac.aaaa=auxI/10000;
        insertarEnLista0rdenado(lista,auxCont,nCampo,asc);
    }
    fclose (arch);
    return 0;
}

void imprimirListaR(tNodo lista){
    tContent auxCont;

    if(lista!=NULL){
        auxCont = lista->content;
        printf("%4d" , auxCont.dni);
        printf("%18s", auxCont.apellido);
        printf("%10s",auxCont.nombre);
        printf("%5d" , auxCont.fechaNac.aaaa);
        printf("%3d", auxCont.fechaNac.mm) ;
        printf("%3d\n", auxCont.fechaNac.dd);
        imprimirListaR(lista->sig);
    }
}

void insertarEnListaOrdenado(tNodo* nodo, tContent contenido, int nCampo, int asc){
    tNodo aux=NULL;
    
    if (*nodo == NULL){ /**INSERTO ULTIMO*/
    *nodo = (tNodo)malloc(sizeof(struct sNodo));
    (*nodo)->content = contenido;
    (*nodo)->sig = NULL;
    }
    else {
        if ( criterioOrden (((*nodo) ->content), contenido, nCampo, asc)){
            aux = (tNodo) malloc(sizeof (struct sNodo));
            aux->sig=(*nodo);
            aux->content = contenido;
            (*nodo)=aux;
        }
        else{
            insertarEnListaOrdenado(&(*nodo)->sig, contenido, nCampo, asc);
        }
    }
}

void leerCadDeArch(FILE* arch, char** arrC, char sep) {
    char car;
    int i=0;
    *(arrC)=malloc(sizeof(char));
    if (!feof (arch)){
        car=fgetc(arch);
    }
    while(!feof (arch) && car!=sep){
        (*(arrC))[i]=car;
        i++;
        *(arrC)=realloc (*(arrC),(i+1)*sizeof(char));
        car=fgetc(arch);
    }
    (*(arrC))[i]='\0';
}

void ordenarElemento(tNodo nodo,tNodo lista, int nCampo, int asc){
    tContent contAux;
    while(lista!=NULL && nodo!=NULL){
        if (criterioOrden(lista->content ,nodo->content, nCampo, asc)){
            contAux =lista->content ;
            lista->content = nodo->content;
            nodo->content = contAux;
        }
        lista = lista->sig;
    }
}

void ordenarLista(tNodo lista, int nCampo, int asc){
    while(lista!=NULL){
        ordenarElemento (lista, lista->sig, nCampo, asc);
        lista = lista->sig;
    }
}
