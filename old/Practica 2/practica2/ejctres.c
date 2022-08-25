#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
///ctes
#define f 20
#define col 20
////estructuras
struct adatos{
    char nombre[f];
    int PTS;
    int PJ;
    int PG;
    int PE;
    int PP;
    int GF;
    int GC;
    int DIF;

};

typedef struct adatos tabla;


////funciones
FILE* abrirarchivo(char nombre[20],char modo[]);
void cargararreglo(FILE* archnombres,FILE* archpuntos,tabla arr[f]);
void imprmirarreglo(FILE* archivo,tabla arr[f]);
///funcion prinicpal
int main(){
    tabla arr[f]={0};
    FILE* arch1;
    FILE* arch2;
    arch1=abrirarchivo("nombres.txt","r");
    arch2=abrirarchivo("contenido.txt","r");
    cargararreglo(arch1,arch2,arr);
    fclose(arch1);
    fclose(arch2);
    arch1=abrirarchivo("titulos.txt","r");
    imprmirarreglo(arch1,arr);
    fclose(arch1);
}
/////funciones
FILE* abrirarchivo(char nombre[20],char modo[]){
    return fopen(nombre,modo);
}
void cargararreglo(FILE* archnombres,FILE* archpuntos,tabla arr[f]){
    int i=0,c=0;
    int letra;
    letra= fgetc(archnombres);
    while (letra!=EOF && i<f-1){
        c=0;
        while(c<f-1 &&(letra!='\n') && (letra!='\n')){
            arr[i].nombre[c]=letra;
            letra=fgetc(archnombres);
            c++;

        }
        arr[i].nombre[c]='\0';
        fscanf(archpuntos,"%d,%d,%d,%d,%d,%d,%d,%d\n",&arr[i].PTS,&arr[i].PJ,&arr[i].PG,&arr[i].PE,&arr[i].PP,&arr[i].GF,&arr[i].GC,&arr[i].DIF);
        i++;
        if (letra!=EOF){
            letra=fgetc(archnombres);
        }

    }
    arr[i].nombre[0]='\0';
}
void imprmirarreglo(FILE* titulos,tabla arr[f]){
    int i,j=0,c=0;
    int letra;
    char arrtitulos[f][col];
    letra=getc(titulos);
    while(letra!=EOF && j<f-1){
        c=0;
        while(c<f-1 &&(letra!='\n') && (letra!='\n')){
            arrtitulos[j][c]=letra;
            letra=getc(titulos);
            c++;
        }
        arrtitulos[j][c]='\0';
        j++;
        if (letra!=EOF){
            letra=fgetc(titulos);
        }
    }
    arrtitulos[j][0]='\0';
    printf("%-20s%6s%6s%6s%6s%6s%6s%6s%6s\n",arrtitulos[0],arrtitulos[1],arrtitulos[2],arrtitulos[3],arrtitulos[4],arrtitulos[5],arrtitulos[6],arrtitulos[7],arrtitulos[8]);
    printf("-----------------------------------------------------------------------\n");
    for(i=0;arr[i].nombre[0]!='\0';i++){
        if (arr[i].DIF>0){
            printf("%-20s%6d%6d%6d%6d%6d%6d%6d%+6d\n",arr[i].nombre,arr[i].PTS,arr[i].PJ,arr[i].PG,arr[i].PE,arr[i].PP,arr[i].GF,arr[i].GC,arr[i].DIF);

        }
        else{
            printf("%-20s%6d%6d%6d%6d%6d%6d%6d%6d\n",arr[i].nombre,arr[i].PTS,arr[i].PJ,arr[i].PG,arr[i].PE,arr[i].PP,arr[i].GF,arr[i].GC,arr[i].DIF);

        }
    }
}