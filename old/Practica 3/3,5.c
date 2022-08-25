#include <stdio.h>

typedef struct{
    int a, b, c;
}t_tres;

void ordernar(t_tres *p);

void ordernar(t_tres *p){
    int arr[3] = {p->a, p->b, p->c};
    int aux;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (arr[i] < arr[j]){
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    p->a = arr[0];
    p->b = arr[1];
    p->c = arr[2];
}

void main(){
    t_tres a = {7,3,6};
    ordernar(&a);
    printf("%d %d %d\n",a.a,a.b,a.c);
}