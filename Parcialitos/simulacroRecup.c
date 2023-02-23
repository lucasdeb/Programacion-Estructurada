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
void insertarEnListaOrdenado(t_nodo* nodo, t_registro datos);

t_datos cargarDatos(){
    t_datos datos;
    FILE* arch = fopen("datos.csv","r");
    int i = 0, j = 0;
    char c;

    c = fgetc(arch);

    datos.fila = malloc(sizeof(t_registro));

    while (c!=EOF){
        (datos.fila[i]).loc = malloc(sizeof(char));
        for (j = 0;c!=','; j++){
            (datos.fila[i]).loc[j] = c;
            (datos.fila[i]).loc = realloc((datos.fila[i]).loc,sizeof(char)*(j+2));
            c = fgetc(arch);
        }
        (datos.fila[i]).loc[j] = '\0';
        fscanf(arch,"%f,%d,%d\n",&((datos.fila[i]).sup),&((datos.fila[i]).pob),&((datos.fila[i]).anio));
        i++;
        c = fgetc(arch);
        datos.fila = realloc(datos.fila,sizeof(t_registro)*(i+2));
    }
    datos.len = i;
    fclose(arch);

    return datos;
}

void mostrarTabla(t_datos datos){
    int i = 0;
    while(i<datos.len){
        printf("%20s %10.2f %10d %10d\n",((datos.fila[i]).loc),((datos.fila[i]).sup),((datos.fila[i]).pob),((datos.fila[i]).anio));
        i++;
    }
}

t_nodo filtrarDatos(t_datos d,int anio,int pob){
	t_nodo pila = NULL;

    for (int i = 0; i < d.len; i++){
        push(&pila,d.fila[i]);
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
    t_nodo aux = (*pila);
    datos = aux->dato;
    (*pila) = aux->sig;
    free(aux);
    return datos;
}

void desapilarInsertarEnLista(t_nodo* pila, t_nodo* lst){
    t_registro datos;

    while(*pila!=NULL){
        datos = pop(pila);
        insertarEnListaOrdenado(lst,datos);
    }
}

void insertarEnListaOrdenado(t_nodo* nodo, t_registro datos){
    t_nodo aux = NULL;
    if((*nodo) == NULL){
        (*nodo) = malloc(sizeof(struct s_nodo));
        (*nodo)->dato = datos;
        (*nodo)->sig = NULL;
    }
    else{
        if(datos.anio > ((*nodo)->dato).anio){
            aux = malloc(sizeof(struct s_nodo));
            aux->sig = (*nodo);
            aux->dato = datos;
            (*nodo) = aux;
        }
        else{
            insertarEnListaOrdenado(&(*nodo)->sig, datos);
        }
    }
}

int mostrarPila(t_nodo pila){
    if(pila!=NULL){
        mostrarPila(pila->sig);
        printf("%20s %10.2f %10d %10d\n", pila->dato.loc, pila->dato.sup, pila->dato.pob, pila->dato.anio);
    }
    else{
        return 0;
    }
}

void mostrarLista(t_nodo lista){
    while(lista!=NULL){
        printf("%20s %10.2f %10d %10d\n",lista->dato.loc,lista->dato.sup, lista->dato.pob, lista->dato.anio);
        lista = lista->sig;
    }
}

int main(void){
    t_nodo pila=NULL;
    t_nodo lst=NULL;
	t_datos datos;
	datos=cargarDatos();                   // 1)
	printf("\n= = = ARREGLO DINAMICO CON LOS DATOS = = = =\n");
	mostrarTabla(datos);                   // 2)
	pila=filtrarDatos(datos,2010,300000);  // 3)
	printf("\n= = = = = = = = = PILA = = = = = = = = = = =\n");
	mostrarPila(pila);	                   // 4)
    desapilarInsertarEnLista(&pila,&lst);
    printf("\n= = = = = = = LISTA ORDENADA = = = = = = = =\n");
    mostrarLista(lst);
}