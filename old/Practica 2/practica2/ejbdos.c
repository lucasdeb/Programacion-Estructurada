#include <stdlib.h>
#include <stdio.h>
#include <math.h>
///
#define l 10
#define term -99
///estrcuturas
struct apunto
{
    int x;
    int y;
};
typedef struct apunto punto;
///funciones
FILE* abrirarch(char nombre[20], char tipo[] );
void cargararreglo(FILE* arch,punto arr[11]);
int distancia(punto arr1,punto arr2);
void menordisttotal(punto arr[l]);


///princpal
int main(){
    int dist;
    punto arr[l]={0};
    FILE* arch;
    arch=abrirarch("puntos.txt","r");
    cargararreglo(arch,arr);
    fclose(arch);
    menordisttotal(arr);
    return 0;
}
///funcped
FILE* abrirarch(char nombre[20], char tipo[] ){
    return fopen(nombre,tipo);
}
void cargararreglo(FILE* arch,punto arr[l]){
    punto res={0,0};
    int y,x;
    x=fscanf(arch,"(%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n",&arr[0].x,&arr[0].y,&arr[1].x,&arr[1].y,&arr[2].x,&arr[2].y,&arr[3].x,&arr[3].y,&arr[4].x,&arr[4].y,&arr[5].x,&arr[5].y,&arr[6].x,&arr[6].y,&arr[7].x,&arr[7].y,&arr[8].x,&arr[8].y,&arr[9].x,&arr[9].y);
    arr[10].x=term;
    arr[10].y=term;

}
void menordisttotal(punto arr[l]){
    int distmin=term;
    int i=0,j;
    for(i=0;arr[i].x != term && arr[i].y != term;i++){
        for(j=0;arr[j].x != term && arr[j].y != term;j++){
            if (distmin==term){
                distmin=distancia(arr[i],arr[j]);
            }
            else if(distancia(arr[i],arr[j])<distmin){
                distmin=distancia(arr[i],arr[j]);
            }
        }
    }
    printf("\ndistancia minima es :%d\n",distmin);
}
int distancia(punto arr1,punto arr2){
    int u,v,dis;
    u=pow((arr2.x)-(arr1.x),2);
    v=pow((arr2.y)-(arr1.y),2);
    dis=sqrt(u+v);
    return dis;
}


