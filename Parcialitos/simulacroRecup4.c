#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void insertarEnListaOrdenado(t_nodo* nodo, t_registro datos, int campo, int asc);
int criterioOrden(t_registro conA, t_registro conB, int campo, int asc);

t_datos cargarDatos(){
    t_datos datos;
    int i = 0, j = 0;
    FILE* arch = fopen("datos.csv","r");
    char c;

    c = fgetc(arch);

    datos.fila = malloc(sizeof(t_registro));
    while(c!=EOF){
        (datos.fila[i]).loc = malloc(sizeof(char));
        for (j = 0;c!=','; j++){
            (datos.fila[i]).loc[j] = c;
            (datos.fila[i]).loc = realloc((datos.fila[i].loc),(j+2)*sizeof(char));
            c = fgetc(arch);
        }
        (datos.fila[i]).loc[j] = '\0';
        fscanf(arch,"%f,%d,%d\n",&((datos.fila[i]).sup),&((datos.fila[i]).pob),&((datos.fila[i]).anio));
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
        printf("%-20s %10.2f %10d %10d\n",(datos.fila[i]).loc,(datos.fila[i]).sup, (datos.fila[i]).pob, (datos.fila[i]).anio);
    }
}

void mostrarLista(t_nodo nodo){
    if(nodo!=NULL){
        printf("%-20s %10.2f %10d %10d\n",nodo->dato.loc, nodo->dato.sup, nodo->dato.pob, nodo->dato.anio);
        mostrarLista(nodo->sig);
    }
}

t_nodo cargarLista(t_datos datos, int campo, int asc){
    t_nodo nodo = NULL;
    for (int i = 0; i < datos.len; i++){
        insertarEnListaOrdenado(&nodo,(datos.fila[i]),campo,asc);
    }
    return nodo;
}

void insertarEnListaOrdenado(t_nodo* nodo, t_registro datos, int campo, int asc){
    t_nodo aux = NULL;

    if(*nodo == NULL){
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->dato = datos;
        (*nodo)->sig = NULL;
    }
    else{
        if(criterioOrden(((*nodo)->dato),datos,campo,asc)){
            aux = malloc(sizeof(struct s_nodo));
            aux->dato = datos;
            aux->sig = *nodo;
            *nodo = aux;
        }
        else{
            insertarEnListaOrdenado(&(*nodo)->sig,datos,campo,asc);
        }
    }
}

int criterioOrden(t_registro conA, t_registro conB, int campo, int asc){
    int res = 0;
    if (campo == 0){
        if (asc == 0){
            if (strcmp(conA.loc,conB.loc) == -1){
                res = 1;
            }
        }
        else{
            if (strcmp(conA.loc,conB.loc) == 1){
                res = 1;
            }
        }
    }
    else if(campo == 1){
        if (asc == 0){
            if (conA.sup<conB.sup){
                res=1;
            }
        }
        else{
            if(conA.sup>conB.sup){
                res=1;
            }
        }
        
    }
    else if(campo == 2){
        if(asc == 0){
            if(conA.pob<conB.pob){
                res = 1;
            }
        }
        else{
            if(conA.pob>conB.pob){
                res = 1;
            }
        }
    }
    else if(campo == 3){
        if(asc == 0){
            if(conA.anio<conB.anio){
                res = 1;
            }
        }
        else{
            if(conA.anio>conB.anio){
                res = 1;
            }
        }
    }
    return res;
}

int main(void){
    t_nodo pila = NULL;
    t_nodo lst = NULL;
    t_datos datos;
    datos=cargarDatos();
    printf("-------------ARREGLO DINAMICO-------------\n");
    mostrarTabla(datos);
    lst=cargarLista(datos,0,0);
    printf("--------------LISTA ORDENADA--------------\n");
    mostrarLista(lst);
}