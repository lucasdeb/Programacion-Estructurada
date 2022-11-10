#include <stdio.h>

int cociente(int n,int n1);

int main(void){
    int n,n1;
    printf("Igresar primer numero: ");
    scanf("%d",&n);
    printf("Igresar segundo numero: ");
    scanf("%d",&n1);
    printf("El cociente (como entero): %d",cociente(n,n1)-1);
}

int cociente(int n,int n1){
    if (n<0){
        return 0;
    }
    else{
        return 1 + cociente(n-n1,n1);
    }
}