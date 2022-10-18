#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cargarStrDin1();

int main(void){
    char* str = NULL;
    str = cargarStrDin1();
    // cargarStrDin2(&str);
    escribirArch("frase.txt", str);
    imprimirArch("frase.txt");
}

char* cargarStrDin1(){
    char letra;
    char *arr = NULL;
    arr = (char*)malloc(sizeof(char));

    if(arr == NULL){
        letra = getchar();
    }
    while (letra!='\n'){
        arr = (char*)realloc(arr,sizeof(char)*strlen(arr)+1);
        arr[strlen(arr)] = letra;
        letra = getchar();
    }
    arr[strlen(arr)] = '\0';

    return arr;
    
}
