#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct puntos{
    int x;
    int y;
}; 
typedef struct puntos punto;

void cargarArr(punto p[20]);
float distancia(punto p1, punto p2);
float dConsec(punto p[20]);
float dCual(punto p[20]);

int main(void){
    punto p[20]={0,0};
    cargarArr(p);
    printf("%f\n",distancia(p[0],p[2]));
    printf("%f",dConsec(p));

}

void cargarArr(punto p[20]){
    FILE* arch = fopen("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/new/p2/puntos.csv","r");
    int i=0,r;

    r = fscanf(arch,"%d,%d", &p[i].x, &p[i].y);
    for (i = 1; i < 19 && !feof(arch); i++){
        r = fscanf(arch,"%d,%d", &p[i].x, &p[i].y);
    }
    fclose(arch);
}

float distancia(punto p1, punto p2){
    return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

float dConsec(punto p[20]){
    float min;

    for (int i = 0; i<10; i++){
        for (int j = i+1; j < 11; j++){
            if (i==0){
                min = distancia(p[i],p[j]);
            }
            else{
                if (distancia(p[i],p[j])<min){
                    min = distancia(p[i],p[j]);
                }
            }
        }
    }
    return min;
}