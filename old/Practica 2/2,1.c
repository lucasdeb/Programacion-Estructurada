#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct puntos
{
    int x;
    int y;
};

void calc(struct puntos p, struct puntos p1);

void main(){

    struct puntos p;
    struct puntos p1;

    printf("Ingresar punto x: ");
    scanf("%d",&p.x);
    printf("Ingresar punto y: ");
    scanf("%d",&p.y);
    printf("Ingresar punto x1: ");
    scanf("%d",&p1.x);
    printf("Ingresar punto y1: ");
    scanf("%d",&p1.y);

    calc(p,p1);
}

void calc(struct puntos p, struct puntos p1){
    if (((p.x)^2)+((p.y)^2)>((p1.x)^2)+((p1.y)^2)){
        printf("El punto %d,%d esta mas cerca",p1.x,p1.y);
    }

    else{
        printf("El punto %d,%d esta mas cerca",p.x,p.y);
    }
}