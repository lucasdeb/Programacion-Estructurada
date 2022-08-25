#include <stdio.h>

int f1(int a, int b){
    if(a == 0){
        return 0;
    }
    else{
        return 1 + f1(a-b,b);
    }
}

int main(){
    int a,b;
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    printf("El cociente es: %d\n", f1(a,b));
}