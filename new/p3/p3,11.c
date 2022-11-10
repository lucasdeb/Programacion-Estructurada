#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a, b;
}t_dosint;

void fun1(t_dosint d);
void fun(int *v1, int *v2);

int main(void){
    t_dosint d;
    fun1(d);

}

void fun1(t_dosint d){
    d.a = 2;
    d.b = 3;
    fun(&d.a,&d.b);
}

void fun(int *v1, int *v2){
    int aux = *v1;

    *v1 = *v2;
    *v2 = aux;
    

    printf("%d %d",*v1, *v2);
}