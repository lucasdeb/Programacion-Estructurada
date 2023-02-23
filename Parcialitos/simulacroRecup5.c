#include <stdio.h>
#include <stdlib.h>

struct s_dato{          // ESTRUCTURA para almacenar una FILA
	char* loc;          // localidad (areglo DINAMICO de char)
	float sup;          // superficie
	int pob;            // poblacion
	int anio;           // anio del censo
};
typedef struct s_dato t_registro;

struct s_datos{         // ESTRUCTURA para almacenar los datos del ARCHIVO
	t_registro* fila;   // Arreglo DINAMICO de t_registro
	int len;            // Almacenar el largo del arreglo fila
};
typedef struct s_datos t_datos;

struct s_nodo{       	// ESTRUCTURA para el NODO de la LISTA
	t_registro dato; 	// Informacion del nodo del tipo t_registro
	struct s_nodo* sig; // puntero al siguiente
};
typedef struct s_nodo* t_nodo;

void push(t_nodo* pila, t_registro datos);
t_registro pop(t_nodo* pila);
void desapilarYcargar(t_nodo* pila, t_nodo* lista, int pob, int anio);
void insertarEnListaOrdenado(t_nodo* nodo, t_registro datos);
void desapilarYcargar(t_nodo* pila, t_nodo* lista, int pob, int anio);

t_datos cargarDatos(){
    t_datos datos;
    FILE* arch = fopen("datos.csv","r");
    int i = 0, j = 0;
    char c;
    c = fgetc(arch);

    datos.fila = malloc(sizeof(t_registro));
    while(c!=EOF){
        (datos.fila[i]).loc = malloc(sizeof(char));
        for (j = 0;c!=','; j++){
            (datos.fila[i]).loc[j] = c;
            (datos.fila[i]).loc = realloc((datos.fila[i]).loc,(j+2)*sizeof(char));
            c = fgetc(arch);
        }
        (datos.fila[i]).loc[j] = '\0';
        fscanf(arch,"%f,%d,%d\n",&((datos.fila[i]).sup),&((datos.fila[i]).pob),&((datos.fila[i])).anio);
        datos.fila = realloc(datos.fila,(i+2)*sizeof(t_registro));
        i++;
        c = fgetc(arch);
    }
    datos.len = i;
    fclose(arch);
    return datos;
}

void mostrarTabla(t_datos datos){
    for (int i = 0; i < datos.len; i++){
        printf("%-20s %10.2f %10d %10d\n",(datos.fila[i]).loc, (datos.fila[i]).sup, (datos.fila[i]).pob, (datos.fila[i]).anio);
    }
}

t_nodo cargarPila(t_datos datos){
    t_nodo pila = NULL;
    for (int i = 0; i < datos.len; i++){
        push(&pila,datos.fila[i]);
    }
    return pila;
}

void push(t_nodo* pila, t_registro datos){
    t_nodo aux = malloc(sizeof(struct s_nodo));
    aux->dato = datos;
    aux->sig = *pila;
    *pila = aux;
}

t_registro pop(t_nodo* pila){
    t_registro datos;
    t_nodo aux = *pila;
    datos = aux->dato;
    *pila = aux->sig;
    free(aux);
    return datos;
}

void mostrarLista(t_nodo nodo){
    if(nodo!=NULL){
        mostrarLista(nodo->sig);
        printf("%-20s %10.2f %10d %10d\n",nodo->dato.loc, nodo->dato.sup, nodo->dato.pob, nodo->dato.anio);
    }
}

void desapilarYcargar(t_nodo* pila, t_nodo* lista, int pob, int anio){
    t_registro datos;
    while (*pila!=NULL){
        datos = pop(pila);
        if(datos.pob>pob && datos.anio == anio){
            insertarEnListaOrdenado(lista,datos);
        }
    }
}

void insertarEnListaOrdenado(t_nodo* nodo, t_registro datos){
    t_nodo aux = NULL;
    if(*nodo == NULL){
        (*nodo) = malloc(sizeof(struct s_nodo));
        (*nodo)->dato = datos;
        (*nodo)->sig = NULL;
    }
    else{
        if((*nodo)->dato.pob>datos.pob){
            aux = malloc(sizeof(struct s_nodo));
            aux->dato = datos;
            aux->sig = (*nodo);
            (*nodo) = aux;
        }
        else{
            insertarEnListaOrdenado(&(*nodo)->sig,datos);
        }
    }
}

int main(void){
    t_nodo pila = NULL;
    t_nodo lst = NULL;
    t_datos datos;
    datos=cargarDatos();
    printf("-------------ARREGLO DINAMICO-------------\n");
    mostrarTabla(datos);
    pila = cargarPila(datos);
    printf("---------------PILA CARGADA---------------\n");
    mostrarLista(pila);
    desapilarYcargar(&pila,&lst,30000,2016);
    printf("--------------LISTA ORDENADA--------------\n");
    mostrarLista(lst);
}