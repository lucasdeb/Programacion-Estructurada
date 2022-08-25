#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contenido{
    int dni;
    char *nombre;
    char *apellido;
};
typedef struct contenido cont;

struct nodo{
    cont valores;
    struct nodo* next;
};
typedef struct nodo tNodo;

void imprimir(tNodo p);

void imprimir(tNodo p){
    if (p.next != NULL){
        imprimir(*p.next);
    }
    printf("%d, %s, %s\n", p.valores.dni, p.valores.nombre, p.valores.apellido);
}

int main(){

    cont p[3];
    p[0].dni = 42498701;
    p[0].nombre = "Lucas";
    p[0].apellido = "Debarbieri";
    p[1].dni = 42498702;
    p[1].nombre = "James";
    p[1].apellido = "Siano";
    p[2].dni = 42498703;
    p[2].nombre = "Jack";
    p[2].apellido = "Liguori";

    tNodo p3;
    p3.valores = p[0];
    p3.next = NULL;
    
    tNodo p2;
    p2.valores = p[1];
    p2.next = &p3;

    tNodo p1;
    p1.valores = p[2];
    p1.next = &p2;

    imprimir(p1);


}
