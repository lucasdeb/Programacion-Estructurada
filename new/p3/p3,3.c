#include <stdio.h>
#include <stdlib.h>

void fun(double *p);

void fun(double *p){
    double res = (*p) - (int)(*p);
    printf("%f\n",res);

    if (res>=0.5){
        *p = ((int)(*p)+1);
        printf("%f",*p);
    }
    else{
        printf("%f",*p-res);
    }
}

int main(void){
    double num = 5.5;

    fun(&num);
}