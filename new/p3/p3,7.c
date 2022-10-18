#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cad();

int main(void){
    printf("%s", cad());
}

char *cad(){
    char letra;
    char* arr = NULL;
    arr = (char*)malloc(sizeof(char));

    if (arr == NULL){
        letra = getchar();
    }
    while (letra!='\n'){
        arr = (char*)realloc(arr,sizeof(char)*strlen(arr)+1);
        letra = getchar();
        arr[strlen(arr)] = letra;
    }
    arr[strlen(arr)] = '\0';

    return arr;
    
}