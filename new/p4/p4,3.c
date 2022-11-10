#include <stdio.h>
#include <stdlib.h>

int resto(int n, int n1);

int main(void){
    int n,n1;
    printf("Igresar primer numero: ");
    scanf("%d",&n);
    printf("Igresar segundo numero: ");
    scanf("%d",&n1);
    printf("El cociente (como entero): %d",resto(n,n1));
}

int resto(int n, int n1){
    if (n==0 || n==1){
        return n;
    }
    else{
        return resto(n-n1,n1);
    }
}