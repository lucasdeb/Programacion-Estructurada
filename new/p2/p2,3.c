#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 15
#define F 100

struct s_punto{
    char nombre[L];
    int PTS, PJ, PG, PE, PP, GF, GC, DIF;
}; 
typedef struct s_punto t_punto;

void cargarArr(t_punto arr[L], char nAP[F], char nAE[F]);
void imprimirTabla(t_punto arr[L]);
void ordenarTabla(t_punto arr[L], char nomArchT[F]);
int lenMatriz(t_punto arr[L]);

int main(void){
    t_punto arr[L] = {0};

    cargarArr(arr,"/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/puntos.txt","/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/equipos.txt");
    imprimirTabla(arr);
    ordenarTabla(arr, "/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/old/Practica 1/titulo.txt");
    printf("%d", lenMatriz(arr));
}

int lenMatriz(t_punto arr[L])
{
    int i = 0;
    while (arr[i].PJ != 0 && i < L)
    {
        ++i;
    }
    return i;
}

void cargarArr(t_punto arr[L], char nAP[F], char nAE[F]){
    int r,i=0,j=0;
    FILE* archP = fopen(nAP, "r");
    FILE* archE = fopen(nAE, "r");

    r = fscanf(archE,"%[^\n]\n",arr[i].nombre);

    for (i = 1;i<L; i++){
        r = fscanf(archE,"%[^\n]\n",arr[i].nombre);
    }
    
    r = fscanf(archP,"%d, %d, %d, %d, %d, %d, %d, %d\n", &arr[j].PTS, &arr[j].PJ, &arr[j].PG, &arr[j].PE, &arr[j].PP, &arr[j].GF, &arr[j].GC, &arr[j].DIF);

    for (j = 1;j<L; j++){
        r = fscanf(archP,"%d, %d, %d, %d, %d, %d, %d, %d\n", &arr[j].PTS, &arr[j].PJ, &arr[j].PG, &arr[j].PE, &arr[j].PP, &arr[j].GF, &arr[j].GC, &arr[j].DIF);
    }
    
    fclose(archP);
    fclose(archE);
}

void imprimirTabla(t_punto arr[L]){
    printf("%-20s %-3s %-3s %-3s %-3s %-3s %-3s %-3s %-3s", "Equipos", "PTS", "PJ", "PG", "PE", "PP", "GF", "GC", "DIF");
    printf("\n----------------------------------------------------\n");

    for (int i = 0; i < L && arr[i].PJ!=0; i++){
        printf("%-20s %-3d %-3d %-3d %-3d %-3d %-3d %-3d %-3d\n", arr[i].nombre, arr[i].PTS, arr[i].PJ, arr[i].PG, arr[i].PE, arr[i].PP, arr[i].GF, arr[i].GC, arr[i].DIF);
    }
    printf("\n");
}

void ordenarTabla(t_punto arr[L], char nomArchT[F]){
    int i=0, j=0;
    t_punto aux, arrA[L];
    int len = lenMatriz(arr);

    for (i = 0; i < len-1 ; i++){
        for (j = i+1; j < len; j++){
            if(arr[i].PTS < arr[j].PTS){
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    imprimirTabla(arr);

    for (i = 0; i < len-1 ; i++){
        for (j = i+1; j < len; j++){
            if(arr[i].DIF < arr[j].DIF){
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    imprimirTabla(arr);

    for (i = 0; i < len-1 ; i++){
        for (j = i+1; j < len; j++){
            if(arr[i].GF < arr[j].GF){
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    imprimirTabla(arr);
}