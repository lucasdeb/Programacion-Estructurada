#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

struct datos{
    int dni;
    char nombre[15], pais[10];
}; typedef struct datos d;

void ordenar(d p[N], int col);
void imprimirTabla(d p[N]);

int main(void){
    int col,r,e=0;
    d p[N]={0};

    FILE* arch = fopen("p2,4.txt","r");

    while(!feof(arch)){
        r = fscanf(arch,"%d, %[^,], %[^\n]", &p[e].dni, p[e].nombre, p[e].pais);
        e++;
    }
    
    printf("(1) - Ver listado ordenado por DOCUMENTO\n");
    printf("(2) - Ver listado ordenado por NOMBRE\n");
    printf("(3) - Ver listado ordenado por PAIS\n");
    printf("(4) - Salir del programa\n");
    scanf("%d", &col);

    while ((col!=0) && (col<4)){
        ordenar(p, col);
        imprimirTabla(p);
        if(0<col<4){
            printf("(1) - Ver listado ordenado por DOCUMENTO\n");
            printf("(2) - Ver listado ordenado por NOMBRE\n");
            printf("(3) - Ver listado ordenado por PAIS\n");
            printf("(4) - Salir del programa\n");
            scanf("%d", &col);
        }
    }
}

int lenMatriz(d p[N])
{
    int i = 0;
    while (p[i].dni != 0 && i < N)
    {
        i++;
    }
    return i;
}

void ordenar(d p[N], int col){
    int r,e=0;
    d temps;
    int len = lenMatriz(p);

    if (col==1){
        for (int i = 0; i < len-1; i++){
            for (int j = i+1; j < len; j++){
                if(p[i].dni<p[j].dni){
                    temps = p[i];
                    p[i] = p[j];
                    p[j] = temps;
                }
            }
        }
    }
    else if(col==2){
        for (int i = 0; i < len-1; i++){
            for (int j = i+1; j < len; j++){
                if(strcmp(p[i].nombre,p[j].nombre)>0){
                    temps = p[i];
                    p[i] = p[j];
                    p[j] = temps;
                }
            }
        }
    }
    else if(col==3){
        for (int i = 0; i < len-1; i++){
            for (int j = i+1; j < len; j++){
                if(strcmp(p[i].pais,p[j].pais)>0){
                    temps = p[i];
                    p[i] = p[j];
                    p[j] = temps;
                }
            }
        }
    }
}

void imprimirTabla(d p[N]){
    int i=0;
    printf("\n%-15s %-15s %-5s","Documento","Nombre", "Pais");
    printf("\n==========================================\n");

    while (p[i].dni!=0){
        printf("%-15d %-15s %-5s\n", p[i].dni, p[i].nombre, p[i].pais);
        i++;
    }
    printf("\n");
}