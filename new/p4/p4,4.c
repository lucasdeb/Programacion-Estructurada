#include <stdio.h>
#include <stdlib.h>

int* cargarArr();
void invertir(int *p, unsigned int n);

int main(void){
    int* p = cargarArr();
    for (int j = 0; p[j]!=0; j++){
        printf(" - %d",p[j]);
    }
    invertir(p,9);
    for (int j = 0; p[j]!=0; j++){
        printf(" - %d",p[j]);
    }
}

int* cargarArr(){
    int *p = NULL;
    int n,i=0;
    p = malloc(sizeof(int));

    scanf("%d",&n);

    while(n!=0){
        p[i] = n;
        printf("Valor: %d Dir: %d\n",p[i],(p+i));
        i++;
        p = realloc(p,sizeof(int)*(i+1));
        scanf("%d",&n);
    }
    p[i] = 0;

    return p;
}

void invertir(int *p, unsigned int n){
    int aux;
    if(n>1){
        aux = p[n-1];
        p[n-1] = p[0];
        p[0] = aux;
        invertir(p+1,n-2);
    }
}