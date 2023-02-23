#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RESUMEN PARCIAL //
// FRANCO GUAITA //
// DUDAS AL MD //

struct sPersonas
{
    char * nombre;
    char * apellido;
    int dni;
};
typedef struct sPersonas Personas;

struct sNodo
{
    int numero;
    struct sNodo * sig;
};
typedef struct sNodo * NodoInt;

struct sNodo2
{
    Personas per;
    struct sNodo2 * sig;
};
typedef struct sNodo2 * NodoPer;

struct sCola
{
    NodoPer frente;
    NodoPer final;
};
typedef struct sCola tCola;

// FUNCIONES PILAS

void push(NodoPer * pila, Personas datos);
Personas pop(NodoPer * pila);
void imprimirPila(NodoPer pila);

// FUNCIONES LISTAS

void insertarEnLista(NodoPer * nuevoNodo, Personas datos);
void insertarEnListaOrdenado(NodoPer * nuevoNodo, Personas datos);
void imprimirLista(NodoPer lista);
Personas eliminarNodo(NodoPer * nuevoNodo, int val);
Personas eliminarNodoPosicion(NodoPer * nuevoNodo, int pos);

// FUNCIONES LISTAS + PILAS

void desapilarInsertarEnLista(NodoPer * pila, NodoPer * lista);

// FUNCIONES COLAS

void enqueue(tCola * cola, Personas datos);
Personas dequeue(tCola * cola); 
void imprimirCola(tCola cola);

// FUNCIONES LISTAS + COLAS

void desencolarInsertarEnLista(tCola * cola, NodoPer * lista);

int main()
{
    /* 
    TODAS LAS FUNCIONES FUERON HECHAS USANDO COMO DATOS
    OTRA ESTRUCTURA (PERSONAS).
    */
    
    // INSERTAR DATOS EN PILA //

    NodoPer pila = NULL;

    int i = 0;

    // ASIGNACION DE ARRAY DINAMICO

    Personas * arr = malloc(sizeof(struct sPersonas));

    arr[i].nombre = "Lionel";
    arr[i].apellido = "Messi";
    arr[i].dni = 10;

    push(&pila, arr[i]);
    i++;

    arr = realloc(arr, (i + 1) * sizeof(struct sPersonas));

    arr[i].nombre = "Rodrigo";
    arr[i].apellido = "De Paul";
    arr[i].dni = 7;

    push(&pila, arr[i]);
    i++;

    arr = realloc(arr, (i + 1) * sizeof(struct sPersonas));

    arr[i].nombre = "Giovani";
    arr[i].apellido = "Lo Sexo";
    arr[i].dni = 20;

    push(&pila, arr[i]);

    printf("PILA: \n");
    imprimirPila(pila);

    // POP

    pop(&pila);
    printf("\nPOP: \n");
    imprimirPila(pila);

    printf("\n-------------------------\n");

    // INSERTAR DATOS EN LISTA //

    NodoPer lista = NULL;
    NodoPer lista2 = NULL;
    NodoPer lista3 = NULL;

    i = 0;
    insertarEnLista(&lista, arr[i]);

    i++;
    insertarEnLista(&lista, arr[i]);

    i++;
    insertarEnLista(&lista, arr[i]);

    //insertarEnListaOrdenado(&lista, arr[i]);

    printf("\nLISTA:\n");
    imprimirLista(lista);

    // INSERTAR DATOS EN LISTA DESDE PILA

    desapilarInsertarEnLista(&pila, &lista2);

    printf("\nDESAPILAR EN LISTA: \n");
    imprimirLista(lista2);

    printf("\n-------------------------\n");

    // COLAS

    tCola cola = {NULL, NULL};

    i = 0;
    enqueue(&cola, arr[i]);

    i++;
    enqueue(&cola, arr[i]);

    i++;
    enqueue(&cola, arr[i]);

    printf("\nCOLA: \n");
    imprimirCola(cola);

    // DEQUEUE

    printf("\nDEQUEUE: \n");
    dequeue(&cola);
    imprimirCola(cola);

    // INSERTAR DATOS EN LISTA DESDE COLA

    desencolarInsertarEnLista(&cola, &lista3);

    printf("\nDESENCOLAR EN LISTA: \n");
    imprimirLista(lista3);

    // ELIMINAR NODO

    printf("\n-------------------------\n");\

    printf("\nLISTA: \n");
    imprimirLista(lista);

    printf("\nELIMINAR NODO EN POSICION 1: \n");
    eliminarNodoPosicion(&lista, 1);
    imprimirLista(lista);

    printf("\nELIMINAR NODO DNI = 10: \n");
    eliminarNodo(&lista, 10);
    imprimirLista(lista);

    return 0;
}

// PILAS

void push(NodoPer * pila, Personas datos)
{
    NodoPer aux;

    aux = (NodoPer) malloc(sizeof(struct sNodo2));

    aux -> per = datos;
    aux -> sig = (*pila);
    (*pila) = aux;
}

Personas pop(NodoPer * pila)
{
    Personas dato;
    NodoPer aux = (*pila);

    dato = aux -> per;
    (*pila) = aux -> sig;
    free(aux);

    return dato;
}

void imprimirPila(NodoPer pila)
{
    if (pila != NULL)
    {
        printf("%s %s %d\n", pila -> per.nombre, pila -> per.apellido, pila -> per.dni);
        imprimirPila(pila -> sig);
    }
}

// LISTAS

void insertarEnLista(NodoPer * nuevoNodo, Personas datos)
{
    if ((*nuevoNodo) == NULL)
    {
        (*nuevoNodo) = (NodoPer) malloc(sizeof(struct sNodo2));
        (*nuevoNodo) -> per = datos;
        (*nuevoNodo) -> sig = NULL;
    }

    else
    {
        insertarEnLista(&((*nuevoNodo) -> sig), datos);
    }
}

void insertarEnListaOrdenado(NodoPer * nuevoNodo, Personas datos)
{
    NodoPer aux = NULL;
    Personas auxDatos;

    if ((*nuevoNodo) == NULL)
    {
        (*nuevoNodo) = (NodoPer) malloc(sizeof(struct sNodo2));
        (*nuevoNodo) -> per = datos;
        (*nuevoNodo) -> sig = NULL;
    }

    else
    {
        if ((*nuevoNodo) -> per.dni > datos.dni)
        {
            aux = (NodoPer) malloc(sizeof(struct sNodo2));
            aux -> per = datos;
            aux -> sig = (*nuevoNodo);
            (*nuevoNodo) = aux;
        }

        else
        {
            insertarEnListaOrdenado(&((*nuevoNodo) -> sig), datos);
        }   
    } 
}

void imprimirLista(NodoPer lista)
{
    Personas aux;

    if (lista != NULL)
    {
        aux = lista -> per;
        printf("%s %s %d\n", aux.nombre, aux.apellido, aux.dni);
        imprimirLista(lista -> sig);
    }
}

Personas eliminarNodo(NodoPer * nuevoNodo, int val)
{
    NodoPer aux = NULL;
    Personas data;

    if ((*nuevoNodo) != NULL)
    {
        if ((*nuevoNodo) -> per.dni != val)
        {
            eliminarNodo(&((*nuevoNodo) -> sig), val);
        }

        else
        {
            aux = (*nuevoNodo);
            data = aux -> per;
            (*nuevoNodo) = (*nuevoNodo) -> sig;
            free(aux);
        }
    }

    return data;
}

Personas eliminarNodoPosicion(NodoPer * nuevoNodo, int pos)
{
    NodoPer aux = NULL;
    Personas data;

    if ((*nuevoNodo) != NULL)
    {
        if (pos > 0)
        {
            data = eliminarNodoPosicion(&((*nuevoNodo) -> sig), pos - 1);
        }

        else if (pos == 0)
        {
            aux = (*nuevoNodo);
            data = aux -> per;
            (*nuevoNodo) = (*nuevoNodo) -> sig;
            free(aux);
        }
    }

    return data;
}

// LISTAS + PILAS

void desapilarInsertarEnLista(NodoPer * pila, NodoPer * lista)
{
    Personas aux;

    while ((*pila) != NULL)
    {
        aux = pop(pila);
        insertarEnLista(lista, aux);
    }
}

// COLAS

void enqueue(tCola * cola, Personas datos)
{
    NodoPer aux = (NodoPer) malloc(sizeof(struct sNodo2));

    aux -> per = datos;
    aux -> sig = NULL;

    if (cola -> frente == NULL && cola -> final == NULL)
    {
        cola -> frente = aux;
        cola -> final = aux;
    }

    else
    {
        cola -> final -> sig = aux;
        cola -> final = aux;
    }
}

Personas dequeue(tCola * cola)
{
    Personas datos;
    NodoPer aux = cola -> frente;

    datos = aux -> per;
    cola -> frente = aux -> sig;
    free(aux);

    if (cola -> frente == NULL)
    {
        cola -> final = NULL;
    }

    return datos;
}

void imprimirCola(tCola cola)
{
    NodoPer aux = cola.frente;

    while (aux != NULL)
    {
        printf("%s %s %d\n", aux -> per.nombre, aux -> per.apellido, aux -> per.dni);
        aux = aux -> sig;
    }
}

// LISTAS + COLAS

void desencolarInsertarEnLista(tCola * cola, NodoPer * lista)
{
    Personas datos;

    while (cola -> frente != NULL && cola -> final != NULL)
    {
        datos = dequeue(cola);
        insertarEnLista(lista, datos);
    }
}