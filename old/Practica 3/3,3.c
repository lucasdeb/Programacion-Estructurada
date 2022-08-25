#include <stdio.h>

void redondear(double *p);

void redondear(double *p){
    double e = (*p) - (int)(*p);
    if (e>=0.5){
        *p = *p + (1-e);
    }
    else{
        *p = *p - e;
    }
    printf("%f\n",*p);
}

void main(){
    double n = 5.5;
    redondear(&n);
}