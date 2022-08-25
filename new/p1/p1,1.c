#include <stdlib.h>
#include <stdio.h>

void redondeo(float num);

void redondeo(float num){
    int piso, techo, redondeo;
    float resto = num - (int)num;
    if (resto>=0.5){
        piso = (int)num;
        techo = (int)num+1;
        redondeo = (int)num+1;
    }
    else if (resto<0.5&&resto!=0){
        piso = (int)num;
        techo = (int)num+1;
        redondeo = (int)num;
    }
    else {
        piso = (int)num;
        techo = (int)num;
        redondeo = (int)num;
    }
    printf("Piso: %d Techo: %d Redondeo: %d",piso,techo,redondeo);
}

void main(){
    float num;
    scanf("%f", &num);
    redondeo(num);
}