#include <stdio.h>

typedef struct{
int n, o , p;
char p1[26], p2[50];
double a, b, c;
}t_varios;

void main(){
    t_varios a = {1,2,3,"hola","adios",5.5,6.6,7.7};
    printf("%d\n",sizeof(a.n));
    printf("%d\n",sizeof(t_varios));
}