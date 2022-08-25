#include <stdlib.h>
#include <stdio.h>
////ctes
#define largo 20
////estruc
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
void ordenarest(datos arr[largo], int modo);
void cambiarint(int destino, int origen);
int mayor(char arr1[largo],char arr2[largo]);
void cambiar(char arrdestino[largo], char arrorigen[largo]);
char amin(char letra);
void menu(int num, datos arr[largo]);

///funciones p
int main(){
    FILE *arch;
    int num=0;
    datos arr[largo]={0};
    arch=abrirarch("personas.txt","r");
    cargarestruc(arch,arr);
    fclose(arch);
    printf("\n");

    menu(num,arr);

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
        printf("%-10d %20s  %20s\n",arr[i].numdoc,arr[i].nombre,arr[i].pais);

    }
}
void ordenarest(datos arr[largo], int modo){
    int f1,f2,aux=0;
    for(f1=0;arr[f1].numdoc!=0;f1++){
        for(f2=f1+1;arr[f2].numdoc!=0;f2++){
            //if (modo==1){
            if(mayor(arr[f1].nombre,arr[f2].nombre)==1 && modo==1){
                cambiar(arr[f2].nombre,arr[f1].nombre);
                cambiar(arr[f2].pais,arr[f1].pais);
                //cambiarint(arr[f2].numdoc,arr[f1].numdoc);
                aux=arr[f1].numdoc;
                arr[f1].numdoc=arr[f2].numdoc;
                arr[f2].numdoc=aux;
            }
            if(mayor(arr[f1].pais,arr[f2].pais)==1 && modo==3){
                cambiar(arr[f2].nombre,arr[f1].nombre);
                cambiar(arr[f2].pais,arr[f1].pais);
                //cambiarint(arr[f2].numdoc,arr[f1].numdoc);
                aux=arr[f1].numdoc;
                arr[f1].numdoc=arr[f2].numdoc;
                arr[f2].numdoc=aux;
            }
            if((arr[f1].numdoc > arr[f2].numdoc) && modo==2){
                cambiar(arr[f2].nombre,arr[f1].nombre);
                cambiar(arr[f2].pais,arr[f1].pais);
                //cambiarint(arr[f2].numdoc,arr[f1].numdoc);
                aux=arr[f1].numdoc;
                arr[f1].numdoc=arr[f2].numdoc;
                arr[f2].numdoc=aux;
            }

            //}
            
            
        }
    }
}
void cambiar(char arrdestino[largo], char arrorigen[largo]){
    char aux[largo];
    int i;
    for(i=0;i<largo-1 ;i++){ /// es mejor poner eso quelo otro xq sino dependen del largo de una
        aux[i]=arrorigen[i];
        arrorigen[i]=arrdestino[i];
        arrdestino[i]=aux[i];
    }
}
int mayor(char arr1[largo],char arr2[largo]){
    int i, cont1=0 ,cont2=0, res;
    for(i=0;arr1[i]!='\0'&& arr2[i]!='\0';i++){
        cont1+=(int)amin(arr1[i]);
        cont2+=(int)amin(arr2[i]);

    }
    if (cont1> cont2){
        res=1;
    }
    else if(cont2>cont1){
        res=0;
    }
    return res;

}
void cambiarint(int destino, int origen){
    int aux=0;
    aux=origen;
    origen=destino;
    destino=aux;

}
char amin(char letra){
    char aux;
    if (letra>='A' && letra<='Z'){
        return letra+32;
    }
}
void menu(int num, datos arr[largo]){
    printf("1- Ver listado ordenado por nombre\n2- Ver listado ordenado por documento\n3- Ver listado ordenado por país\n4- Salir del programa\n");
    scanf("%d",&num);
    while (num>=1 && num<=3){
        ordenarest(arr,num);
        printf("%-20s%10s%20s\n-------------------------------------------------\n","Documento","Nombre","Pais");
        imprimirestruc(arr);
        printf("1- Ver listado ordenado por nombre\n2- Ver listado ordenado por documento\n3- Ver listado ordenado por país\n4- Salir del programa\n");
        scanf("%d",&num);
        
    }
    printf("\n");
}