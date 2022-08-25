#include <stdlib.h>
#include <stdio.h>
#define L 100;
void funcion(int num);
int main(){
    int num;
    printf("ingrese numero que desee llenar con 0 ");
    scanf("%d",&num);
    funcion(num);
    return 0;
}
void funcion(int num){
    int mask=1,i,nuevo;
    for(i=0;((num>>i)|(mask))!=1;i++){
        printf("%d\n",num>>i);
    }
}