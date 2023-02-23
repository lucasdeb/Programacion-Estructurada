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

void push(t_nodo* pila, t_registro* datos);
t_registro pop(t_nodo* pila);
void insertarEnListaOrdenado(t_nodo* nodo, t_registro datos);

t_datos cargarDatos(){
    t_datos datos;
    FILE* arch = fopen("datos.csv","r");
    int i = 0, j = 0;
    char c;
    c = fgetc(arch);
    datos.fila = malloc(sizeof(struct s_dato));

    while(!feof(arch)){
        (datos.fila[i]).loc = malloc(sizeof(char));
        for (j = 0;c!=','; j++){
            (datos.fila[i]).loc[j] = c;
            (datos.fila[i]).loc = realloc((datos.fila[i]).loc,(j+2)*sizeof(char));
            c = fgetc(arch);
        }
        (datos.fila[i]).loc[j] = '\0';
        fscanf(arch,"%f,%d,%d\n",&((datos.fila[i]).sup),&((datos.fila[i]).pob),&((datos.fila[i]).anio));
        datos.fila = realloc(datos.fila,(i+2)*sizeof(struct s_dato));
        i++;
        c = fgetc(arch);
    }
    datos.len = i;
    fclose(arch);
    return datos;
}

void mostrarTabla(t_datos datos){
    int i = 0;
    while (i<datos.len){
        printf("%-20s %10.2f %10d %10d\n",((datos.fila[i]).loc), ((datos.fila[i]).sup), ((datos.fila[i]).pob), ((datos.fila[i]).anio));
        i++;
    }
}

t_nodo cargarPila(t_datos datos, int pob, int anio){
    t_nodo pila = NULL;
    for (int i = 0; i < datos.len; i++){
        if (pob < (datos.fila[i]).pob && anio == (datos.fila[i]).anio){
            push(&pila,&(datos.fila[i]));
        }
    }
    return pila;
}

void push(t_nodo* pila, t_registro* datos){
    t_nodo aux = malloc(sizeof(struct s_nodo));
    aux->dato = *datos;
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

void desapilarYCargar(t_nodo* pila, t_nodo* lst){
    t_registro datos;
    while (*pila!=NULL){
        datos = pop(pila);
        insertarEnListaOrdenado(lst,datos);
    }
}

void insertarEnListaOrdenado(t_nodo* nodo, t_registro datos){
    t_nodo aux = NULL;

    if(*nodo == NULL){
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->dato = datos;
        (*nodo)->sig = NULL;
    }
    else{
        if((*nodo)->dato.pob<datos.pob){
            aux = malloc(sizeof(struct s_nodo));
            aux->dato = datos;
            aux->sig = *nodo;
            *nodo = aux;
        }
        else{
            insertarEnListaOrdenado(&(*nodo)->sig,datos);
        }
    }
}

void mostrarLista(t_nodo pila){
    if(pila!=NULL){
        printf("%-20s %10.2f %10d %10d\n",(pila->dato).loc, (pila->dato).sup, (pila->dato).pob, (pila->dato).anio);
        mostrarLista(pila->sig);
    }
}

int criterioOrden(t_datos datA, t_datos datB, int nCampo, int asc){

    
}

t_nodo cargarLista(t_datos datos, int nCampo, int asc){
    t_nodo nodo = NULL;
    while (i<datos.len){
        insertarEnListaOrdenado(nodo,nCampo,asc);
    }
    

}


int main(void){
    t_nodo pila = NULL;
    t_nodo lst = NULL;
    t_datos datos;
    datos=cargarDatos();
    printf("-------------ARREGLO DINAMICO-------------\n");
    mostrarTabla(datos);
    lst = cargarLista(datos,2,1);
    printf("--------------LISTA ORDENADA--------------\n");
    mostrarLista(pila);
    desapilarYCargar(&pila,&lst);
    printf("---------------PILA CARGADA---------------\n");
    mostrarLista(lst);
}