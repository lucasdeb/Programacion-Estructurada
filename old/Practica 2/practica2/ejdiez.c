#include <stdio.h>
#include <stdlib.h>
int funcion(unsigned int num);
int main(){
    unsigned int num;
    int cant;
    printf("ingrese numero ");
    scanf("%d",&num);
    cant=funcion(num);
    printf("el numero tiene: %d de unos en su binario\n",cant);

    return 0;
}
int funcion(unsigned int num){
    int i=0, mask=1,cant;
    for(i=0;((num>>i)|mask)!=1;i++){
        if(((num>>i)&mask)==1){
            cant+=1;
        }
    }
    return cant+1;
}