/*
#include <stdio.h>
#include <stdlib.h>

#define F 14
#define C 20
#define CC 9
#define FT 14
#define CT 20
#define TERM_DATO -999
#define TERM_STR '\0'

FILE* abrirArchivo(char nomArch[20],char modo[]);
void cargarArrTitulo(FILE* fp, char arr[FT][CT]);
void cargarArregloItem(FILE* fp, char arr[F][C]);
void cargarArregloContenido(FILE* fp, int arr[F][CC]);
void imprimirTitulo(char titulo[FT][CT]);
void imprimirTabla(char item[F][C], int contenido[F][CC]);

int main(){
    FILE* fp;
    char titulo[FT][CT]={0};
    char item[F][C]={0};
    char contenido[F][CC]={0};

    fp = abrirArchivo("titulo.txt","r");
    cargarArrTitulo(fp,titulo);
    fp = abrirArchivo("equipos.txt","r");
    cargarArregloItem(fp,item);
    fp = abrirArchivo("contenido.txt","r");
    cargarArregloContenido(fp,contenido);

    return 0;
}

FILE* abrirArchivo(char nomArch[20],char modo[]){
    return fopen(nomArch,modo);
}

void cargarArrTitulo(FILE* fp, char arr[FT][CT]){
    int j,i,l=0;


    for (int i = 0; l != EOF && l<FT-1; i++){
        for (int j = 0; l != '\n' && l != EOF && l != ',' && l!='\t' && j<CT-1; j++){
            arr[i][j] = l;
            l = fgetc(fp);
        }
        arr[i][j] = TERM_STR;
        if (l!=EOF){
            l = fgetc(fp);
        }
    }
    arr[j][0] = TERM_STR;
}

void cargarArregloItem(FILE* fp, char arr[F][C]){

    int i,j,l=0;

    for (int i = 0; l != EOF && l<F-1; i++){
        for (int j = 0; l != '\n' && l != EOF && l != ',' && l!='\t' && j<C-1; j++){
            arr[i][j] = l;
            l = fgetc(fp);
        }
        arr[i][j] = TERM_STR;
        if (l!=EOF){
            l = fgetc(fp);
        }
    }
    arr[i][0] = TERM_STR;

}

void cargarArregloContenido(FILE* fp, int arr[F][CC]){
    int i=0;

    fscanf(fp,"%d,%d,%d,%d,%d,%d,%d,%d\n", &arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3],&arr[i][4],&arr[i][5],&arr[i][6],&arr[i][7]);
    arr[i][8] = TERM_DATO;
    i=1;
    while(!feof(fp) && i<F-1){
        fscanf(fp,"%d,%d,%d,%d,%d,%d,%d,%d\n", &arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3],&arr[i][4],&arr[i][5],&arr[i][6],&arr[i][7]);
        arr[i][8] = TERM_DATO;
        i++;
    }
    arr[i][0] = TERM_DATO;
}

void imprimirTitulo(char titulo[FT][CT]){
    int i;
    printf("%-20s",titulo[0]);
    for (i = 0; i < FT && titulo[i][0]!= TERM_STR; i++){
        printf("%6s",titulo[i]);
    }
    printf("\n-----------------------------------------------------\n");
    
}

void imprimirTabla(char item[F][C], int contenido[F][CC]){
    int i,j;
    for ( i = 0; item[i][0]!= TERM_STR && i < F; i++){
        printf("%-20s",item[0]);
        for ( j = 0;contenido[i][j]!=TERM_DATO && j < CC; j++){
            if(j==7 && contenido[i][j]>0){
                printf("%+6d",contenido[i][j]);
            }
            else{
                printf("%6d",contenido[i][j]);
            }
            printf("\n");
        }
        
    }
    
}
*/
#include <stdio.h>

#define F 20
#define C 20
#define CT 20
#define FT 20
#define CC 20
#define TERM_DATO -999
#define TERM_STR '\0'

FILE* abrirArchivo(char nomArch[50], char modo[]);
void cargarArrTitulo(FILE* fp, char mat[FT][CT]);
void cargarArrItem(FILE* fp, char mat[F][C]);
void cargarArrContenido(FILE* fp, int mat[F][CC]);
void imprimirTitulo(char mat[FT][CT]);
void imprimirTabla(char item[F][C], int contenido[F][CC]);

int main(void){
    FILE *fp;
    char titulo[FT][CT] = {0};
    char item[F][C] = {0};
    int contenido[F][CC] = {0};

    fp = abrirArchivo("titulo.txt", "r");
    cargarArrTitulo(fp, titulo);
    fclose(fp);
    fp = abrirArchivo("equipos.txt", "r");
    cargarArrItem(fp, item);
    fclose(fp);
    fp = abrirArchivo("contenido.txt", "r");
    cargarArrContenido(fp, contenido);
    fclose(fp);

    imprimirTitulo(titulo);
    imprimirTabla(item, contenido);

    return 0;
}

FILE* abrirArchivo(char nomArch[50], char modo[]){
    return fopen(nomArch, modo);
}

void cargarArrTitulo(FILE* fp, char mat[FT][CT]){
    int f = 0, c = 0, leido;
    leido = fgetc(fp);

    while ((f < FT - 1) && leido != EOF){
        c = 0;
        while ((c < CT - 1) && (leido != EOF) && (leido != '\n') && (leido != ',') && (leido != '\t')){
            mat[f][c] = leido;
            leido = fgetc(fp);
            c++;
        }
        mat[f][c] = TERM_STR;
        f++;
        if (leido != EOF){
            leido = fgetc(fp);
        }
    }
    mat[f][0] = TERM_STR;
}

void cargarArrItem(FILE* fp, char mat[F][C]){
    int f = 0, c = 0, leido;
    leido = fgetc(fp);

    while ((f < F - 1) && (leido != EOF)){
        c = 0;
        while ((c < C - 1) && (leido != EOF) && (leido != '\n') && (leido != '\t') && (leido != ',')){
            mat[f][c] = leido;
            leido = fgetc(fp);
            c++;
        }
        mat[f][c] = TERM_STR;
        f++;
        if (leido != EOF){
            leido = fgetc(fp);
        }
    }
    mat[f][0] = TERM_STR;
}

void cargarArrContenido(FILE* fp, int mat[F][CC]){
    int i = 0;

    fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
    mat[i][8] = TERM_DATO;
    i = 1;
    while (!feof(fp) && i < F - 1){
        fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
        mat[i][8] = TERM_DATO;
        i++;
    }
    mat[i][0] = TERM_DATO;
}

void imprimirTitulo(char mat[FT][CT]){
    int i = 0;
    printf("\n%-20s", mat[0]);
    for (i = 1; i < FT - 1 && mat[i][0] != TERM_STR; i++){
        printf("%6s", mat[i]);
    }
    printf("\n---------------------------------------------------------------------\n");
}

void imprimirTabla(char item[F][C], int contenido[F][CC]){
    int i = 0, j = 0;
    for (i = 0; item[i][0] != TERM_STR && i < F; i++){
        printf("%-20s", item[i]);
        for (j = 0; contenido[i][j] != TERM_DATO && j < CC; j++){
            if (j == 7 && contenido[i][j] > 0){
                printf("%+6d", contenido[i][j]);
            }
            else {
                printf("%6d", contenido[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}