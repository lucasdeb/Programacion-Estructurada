#include <stdio.h>

int funR(int a, int b);

void main(){
    int a,b;

    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d",funR(a,b));
}

int funR(int a, int b){

    if (a!=0){
        return b + funR(a-1,b);
    }
    else {
        return 0;
    }
}