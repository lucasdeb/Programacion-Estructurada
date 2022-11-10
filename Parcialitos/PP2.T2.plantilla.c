//PP2-TEMA-02- SOLUCION
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

void insertarEnListaOrd(t_registro *lst, t_nodo *nodo);


/*
void cargarArrDin(FILE* arch, char **arr){
    *arr = malloc(sizeof(char));
    char c;
    int i = 0;

    c = fgetc(arch);

    while(!feof(arch) && c!=','){
        *(arr+i)=c;
        i++;
        *arr = realloc(*arr,sizeof(char)*(i+1));
        c = fgetc(arch);
    }
	*(arr+i)='\0';
}
*/

t_datos cargarDatos(){
	t_datos datos;
	int i=0,j=0;
	FILE* arch = fopen("datos.csv","r");
	char c = fgetc(arch);

	datos.fila = malloc(sizeof(t_registro));

	while(c!=EOF){
        (datos.fila[i]).loc = malloc(sizeof(char));
		for(j=0;c!=','; j++){
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
	datos.len=i;
    fclose(arch);

	return datos;
}

void mostrarTabla(t_datos datos){
	for(int i=0;i!=datos.len;i++){
        printf("%-30s %.2f %10d %10d\n",datos.fila[i].loc, datos.fila[i].sup, datos.fila[i].pob, datos.fila[i].anio);
	}
}

t_nodo filtrarDatos(t_datos d,int anio,int pob){
	t_nodo lst = NULL;
	int i = 0;
	while(i != d.len){
        if((d.fila[i]).anio == anio && (d.fila[i]).pob < pob){
            insertarEnListaOrd(&(d.fila[i]),&lst);
            i++;
        }
        else{
            i++;
        }
	}
	return lst;
}

void insertarEnListaOrd(t_registro *lst, t_nodo *nodo){
	t_nodo aux = NULL;
    if(*nodo == NULL){
        (*nodo) = malloc(sizeof(struct s_nodo));
        (*nodo)->dato = *lst;
		(*nodo)->sig = NULL;
    }
	else{
		if ((*nodo)->dato.sup < lst->sup){
			aux = malloc(sizeof(struct s_nodo));
			aux->dato = *lst;
			aux->sig = (*nodo);
			*nodo = aux;
		}
		else{
			insertarEnListaOrd(lst, &(*nodo)->sig);
		}
	}
}
void mostrarLst(t_nodo lst){
	if(lst != NULL){
		printf("%-30s %.2f %10d %10d\n",lst->dato.loc, lst->dato.sup, lst->dato.pob, lst->dato.anio);
		mostrarLst(lst->sig);
	}
}

void encolar(t_nodo *nodo, t_registro datos){
	if(*nodo == NULL){
		(*nodo) = malloc(sizeof(t_nodo));
		(*nodo)->dato = datos;
		(*nodo)->sig = NULL;
	}
	else{
		encolar(&(*nodo)->sig,datos);
	}
}

int main(){
	t_nodo lst=NULL;
	t_datos datos;
	datos=cargarDatos();                   // 1)
	printf("\n= = = ARREGLO DINAMICO CON LOS DATOS = = = =\n");
	mostrarTabla(datos);                   // 2)
	lst=filtrarDatos(datos,2010,300000);   // 3)
	printf("\n= = = = LISTA FILTRADA Y ORDENADA = = = = =\n");
	mostrarLst(lst);	                   // 4)
	return 0;
}