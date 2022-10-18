#include <stdio.h>

typedef struct{
int n, o , p;
char p1[26], p2[50];
double a, b, c;
}t_varios;

void intercambiar(t_varios *p, t_varios *p1);

void main(){
    t_varios a = {1,2,3,"hola","adios",5.5,6.6,7.7};
    t_varios b = {4,5,6,"buenas","chau",5.9,6.9,7.9};
    printf("\n(Antes) Los int: n:%d o:%d p:%d\nLos char: p1: %s p2: %s\nLos double: a:%2f b:%2f c%2f\n",a.n, a.o, a.p, a.p1, a.p2, a.a, a.b, a.c);
    printf("\n(Antes) Los int: n:%d o:%d p:%d\nLos char: p1: %s p2: %s\nLos double: a:%2f b:%2f c%2f\n",b.n, b.o, b.p, b.p1, b.p2, b.a, b.b, b.c);
    intercambiar(&a, &b);
    printf("\nLos int: n:%d o:%d p:%d\nLos char: p1: %s p2: %s\nLos double: a:%2f b:%2f c%2f\n",a.n, a.o, a.p, a.p1, a.p2, a.a, a.b, a.c);
    printf("\nLos int: n:%d o:%d p:%d\nLos char: p1: %s p2: %s\nLos double: a:%2f b:%2f c%2f\n",b.n, b.o, b.p, b.p1, b.p2, b.a, b.b, b.c);
    printf("%d\n",sizeof(a.n));
    printf("%d\n",sizeof(t_varios));
}

void intercambiar(t_varios *p, t_varios *p1){
    t_varios aux;

    aux = *p;
    *p = *p1;
    *p1 = aux;
}