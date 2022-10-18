#include <stdlib.h>
#include <stdio.h>
///ctes
#define largo 20
///estructuras
struct apersonas
{
    int numdoc;
    char nombre[largo];
    char pais[largo];
};
typedef struct apersonas datos;
///funcione
FILE* abrirarch(char nombre[largo],char modo[]);
void cargarestruc(FILE* arch, datos arr[largo]);
void imprimirestruc(datos arr[largo]);

///funciones p
int main(){
    FILE *arch;
    datos arr[largo]={0};
    arch=abrirarch("personas.txt","r");
    cargarestruc(arch,arr);
    fclose(arch);
    imprimirestruc(arr);
    return 0;

}
///funciones
FILE* abrirarch(char nombre[largo],char modo[]){
    return fopen(nombre,modo);
}
void cargarestruc(FILE* arch, datos arr[largo]){
    int filas=0,pal1=0,pal2=0,x;
    int letra;
    x=fscanf(arch,"%d,",&arr[filas].numdoc);
    letra=getc(arch);
    while (letra!=EOF && x!=EOF && filas<largo-1 ){
        pal1=0;
        pal2=0;
        while(letra!=','&& (pal1<largo-1) ){
            arr[filas].nombre[pal1]=letra;
            letra=getc(arch);
            pal1++;
        }
        arr[filas].nombre[pal1]='\0';
        letra=getc(arch);
        while(letra!='\n'&& (pal2<largo-1)){
            arr[filas].pais[pal2]=letra;
            letra=getc(arch);
            pal2++;

        }
        arr[filas].pais[pal2]='\0';
        filas++;
        x=fscanf(arch,"%d,",&arr[filas].numdoc); 

        if (letra != EOF){
            letra=getc(arch);
        }
    }
    arr[filas].numdoc=0;
}
void imprimirestruc(datos arr[largo]){
    int i;
    for(i=0;arr[i].numdoc!=0;i++){
        printf("%-10d %20s %20s\n",arr[i].numdoc,arr[i].nombre,arr[i].pais);
    }
}