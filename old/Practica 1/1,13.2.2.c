#include <stdio.h>

#define F 20
#define C 20 

FILE* abrirArchivo(char nomArch[50], char modo[]);
void cargarArrTitulo(FILE* fp, char mat[F][C]);
void cargarArrItem(FILE* fp, char mat[F][C]);
void cargarArrContenido(FILE* fp, int mat[F][C]);
void imprimirTitulo(char mat[F][C]);
void imprimirTabla(char item[F][C], int contenido[F][C]);


void main(){
    FILE* fp;
    char item[F][C]={0};
    char contenido[F][C]={0};
    char titulos[F][C]={0};

    fp = abrirArchivo("titulo.txt", "r");
    cargarArrTitulo(fp, titulos);
    fclose(fp);
    fp = abrirArchivo("equipos.txt", "r");
    cargarArrItem(fp, item);
    fclose(fp);
    fp = abrirArchivo("contenido.txt", "r");
    cargarArrContenido(fp, contenido);
    fclose(fp);

    imprimirTitulo(titulo);
    imprimirTabla(item, contenido);

}

FILE* abrirArchivo(char nomArch[50], char modo[]){
    return fopen(nomArch,modo);
}

void cargarArrTitulo(FILE* fp, char mat[F][C]){
    int c=0;
    
}