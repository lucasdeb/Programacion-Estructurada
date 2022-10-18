//TEMA-01- PLANTILLA
#include <stdio.h>
#include <string.h>
#define TD 100  // tama�o arreglo de datos
#define TT 1    // tama�o arreglo de titulo
#define TC 30   // tama�o de las cadenas

struct s_titu{
	char art[TC],can[TC],pre[TC],cod[TC];
};
typedef struct s_titu t_titu;
struct s_dato{
	char nomArt[TC];
	int cantidad;
	float precio;
	int codigo;
};
typedef struct s_dato t_dato;

int len(t_dato ad[TD]);



void cargarArr(char nomArch[],t_dato ad[TD],t_titu at[1]){
	int i = 0, r;
	FILE *arch;
	
	arch = fopen(nomArch, "r");
	
	r = fscanf(arch, "%[^,],%[^,],%[^,],%[^\n]\n", at[i].art, at[i].can, at[i].pre, at[i].cod);
	
	for (i = 1; !feof(arch); i++)
	{
		r = fscanf(arch, "%[^,],%d,%f,%d\n", ad[i].nomArt, &ad[i].cantidad, &ad[i].precio, &ad[i].codigo);
	}
	
	ad[i].codigo = 0;
}

void imprimirArr(t_dato ad[TD],t_titu at[1]){
	int i = 0;
	
	printf("%20s%10s%10s%13s\n", at[i].art, at[i].can, at[i].pre, at[i].cod);
	for (i = 1; ad[i].codigo != 0; i++)
	{
		printf("%20s%10d%10.3f%13d\n", ad[i].nomArt, ad[i].cantidad, ad[i].precio, ad[i].codigo);
	}
}

void ordenarArr(t_dato ad[TD]){
    t_dato temp;
    int lens = len(ad);

	for(int i=0;ad[i].codigo!=0;i++){
        for(int j=i+1;ad[j].codigo!=0;j++){
            if(strlen(ad[i].nomArt)<strlen(ad[j].nomArt)){
                temp = ad[i];
                ad[i] = ad[j];
                ad[j] = temp;
            }
        }
	}
}

//void imprimirRegistroXFecha(t_dato ad[TD], int anio, int mes, int dia){


//}

int len(t_dato ad[TD]){
    int i=0;

    while(ad[i].codigo!=0){
        i++;
    }
    printf("%d",i);
    return i;
}

int main(){

	t_titu arrTitulo[1]; //Arreglo de un solo elemento
	t_dato arrDatos[TD];

	cargarArr("insumos.txt",arrDatos,arrTitulo);
	printf("\nTABLA ORIGINAL * * * * * * * * * * * * * * * * * * * *\n");

	imprimirArr(arrDatos,arrTitulo);

    len(arrDatos);

	ordenarArr(arrDatos);
	printf("\nTABLA ORDENADA * * * * * * * * * * * * * * * * * * * *\n");
	imprimirArr(arrDatos,arrTitulo);

	//printf("\nBUSQUEDA POR FECHA * * * * * * * * * * * * * * * * * *\n");
	//imprimirRegistroXFecha(arrDatos,22,3,18);
	//imprimirRegistroXFecha(arrDatos,21,4,3);
	//imprimirRegistroXFecha(arrDatos,21,3,3);

	return 0;
}
