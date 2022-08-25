#include <stdio.h>

struct nodo{
    int value;
    struct nodo* next;
};
typedef struct nodo tNodo;

void printList(tNodo *head){
    tNodo *aux = head;
    while (aux != NULL){
        printf("%d - ", aux->value);
        aux = aux->next;
    }
}

int main(){
    tNodo n1,n2,n3;
    tNodo *head;

    n1.value = 1;
    n2.value = 2;
    n3.value = 3;

    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;

    printList(head);

    return 0;
}