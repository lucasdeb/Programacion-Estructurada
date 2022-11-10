#include <stdio.h>
#include <stdlib.h>

int producto(int n, int n1);

int main(void){
    int n,n1;
    printf("Igresar primer numero: ");
    scanf("%d",&n);
    printf("Igresar segundo numero: ");
    scanf("%d",&n1);
    printf("%d",producto(n,n1));
}

int producto(int n, int n1){

    if (n1!=0){
        return n + producto(n,n1-1);
    }
    else{
        return 0;
    }
}