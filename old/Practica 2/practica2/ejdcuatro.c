#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
////////////////////////ctes
#define N 10
#define term 0
#define largo 20
///////////////////////estructura


///////funciones
FILE* abrirarch(char nombre[largo],char modo[]);
void subircontenido(FILE* arch);
void escribirarr(char arr[largo]);

//////fun prinicpal
int main(){
    FILE* arch;
    arch=abrirarch("personas.txt","w");
    subircontenido(arch);
    fclose(arch);
    return 0;
}
//////funciones
FILE* abrirarch(char nombre[largo],char modo[]){
    return fopen(nombre,modo);
}
void subircontenido(FILE* arch){
    int cant=0,dni=0;
    char nombre[largo],pais[largo];
    printf("ingrese DNI de persona Num %d: ",cant);
    scanf("%d",&dni);
    while ((cant<N)&& dni!=0){
        printf("ingresar nombre: ");
        fflush(stdin);
        escribirarr(nombre);
        escribirarr(nombre);
        printf("ingresar pais: ");
        escribirarr(pais);
        fprintf(arch,"%d,%s,%s\n",dni,nombre,pais);
        cant++;
        printf("ingrese DNI de persona Num %d: ",cant);
        scanf("%d",&dni);


    }
}
void escribirarr(char arr[largo]){
    int i=0;
    char letra;
    fflush(stdin);
    letra=getchar();
    for(i=0;letra!='\n' && i<largo-1;i++){
        arr[i]=letra;
        fflush(stdin);
        letra=getchar();
    }
    arr[i]='\0';
}