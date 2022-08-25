#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F 3
#define C 100

void cargarMatTxt(char matTxt[F][C]);
void imprimirMatTxt(char matTxt[F][C]);
void ordenarMatText(char matTxt[F][C]);

void main(){
    char matTxt[F][C];

    cargarMatTxt(matTxt);
    imprimirMatTxt(matTxt);
    ordenarMatText(matTxt);
    imprimirMatTxt(matTxt);
}

void imprimirMatTxt(char matTxt[F][C]){
    int i = 0,j = 0;

    for (i=0;i<F;i++){
        for (j=0;matTxt[i][j]!='\0';j++){
            printf("%c ",matTxt[i][j]);
        }
        printf("\n");
    }
}

void cargarMatTxt(char matTxt[F][C]){
    int f,c;
    char aux;
    fflush(stdin);
    for (f = 0;f<F; f++){
        printf("[%d]: ",f+1);
        aux = getchar();
        for (c = 0;aux!='\n';c++){
            matTxt[f][c] = aux;
            aux = getchar();
        }
        matTxt[f][c] = '\0';
    }
}

void ordenarMatText(char matTxt[F][C]){
    int f,c,x,y,aux;
    char temp = '\0';
    char arr[C];


    /*

    for (f = 0;f < F; f++){
        for (c = 0; c < f-1; c++){
            arr[aux] = matTxt[f][c];
            aux++;
        }
    }
    arr[aux] = '\0';

    for(x = 0; x < C - 1; x++){
        for(y = 0; y < C - x - 1; y++){
            if(arr[y] > arr[y+1]){
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
            }
        }
    }

    aux = 0;
    for (f = 0;f<F; f++){
        for (c = 0;c<C;c++){
            matTxt[f][c] = arr[aux];
            aux++;
        }
        matTxt[f][c] = '\0';
    }
    */
}