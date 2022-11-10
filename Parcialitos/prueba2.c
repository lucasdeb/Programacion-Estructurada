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

struct s_cola{
	t_nodo frente;
	t_nodo final;
};
typedef struct s_cola t_cola;

t_registro dequeue(t_cola *cola);

void mostrarLst(t_cola cola){
    while(cola.final != NULL && cola.frente != NULL){
        t_registro datos = dequeue(&cola);
        printf("%-20s %.2f %10d %10d\n",datos.loc, datos.sup, datos.pob, datos.anio);
    }
}

void queue(t_cola *cola, t_registro datos){
    t_nodo aux = malloc(sizeof(struct s_nodo));
    aux->dato = datos;
    aux->sig = NULL;
    if(cola->frente == NULL && cola->final == NULL){
        cola->frente = aux;
        cola->final = aux;
    }
    else{
        cola->final->sig = aux;
        cola->final = aux;
    }
}

t_registro dequeue(t_cola *cola){
    t_registro datos;
    t_nodo aux = cola->frente;
    cola->frente = cola->frente->sig;
    datos = aux->dato;
    free(aux);
    if(cola->frente == NULL){
        cola->final = NULL;
    }
    return datos;

}

t_cola filtrarDatos(t_datos d,int anio,int pob){
    t_cola lst = {NULL,NULL};
    int i = 0;
    while(i!=d.len){
        queue(&lst,d.fila[i]);
        i++;
    }
    return lst;
}

void mostrarTabla(t_datos datos){
    for (int i = 0; i < datos.len; i++){
        printf("%-20s %.2f %10d %10d\n",datos.fila[i].loc, datos.fila[i].sup, datos.fila[i].pob, datos.fila[i].anio);
    }
}

t_datos cargarDatos(){
    t_datos datos;
    FILE* arch = fopen("datos.csv","r");
    int i = 0, j = 0;
    char c;
    c = fgetc(arch);

    datos.fila = malloc(sizeof(t_registro));

    while (c!=EOF){
        (datos.fila[i]).loc = malloc(sizeof(char));
        for (j = 0;c!=EOF && c!=','; j++){
            datos.fila[i].loc[j] = c;
            datos.fila[i].loc = realloc(datos.fila[i].loc, sizeof(char)*(j+2));;
            c = fgetc(arch); 
        }
        datos.fila[i].loc[j] = '\0';
        fscanf(arch,"%f,%d,%d\n",&((datos.fila[i]).sup),&((datos.fila[i]).pob), &((datos.fila[i]).anio));
        datos.fila = realloc(datos.fila,sizeof(t_registro)*(i+2));
        i++;
        c = fgetc(arch);
    }
    datos.len = i;
    fclose(arch);

    return datos;
}

int main(void){
    t_cola lst = {NULL,NULL};
	t_datos datos;
	datos=cargarDatos();                   // 1)
	printf("\n= = = ARREGLO DINAMICO CON LOS DATOS = = = =\n");
	mostrarTabla(datos);                   // 2)
	lst=filtrarDatos(datos,2010,300000);   // 3)
	printf("\n= = = = LISTA FILTRADA Y ORDENADA = = = = =\n");
	mostrarLst(lst);	                   // 4)
}