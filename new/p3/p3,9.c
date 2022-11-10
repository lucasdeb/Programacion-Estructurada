#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* subcadena(char *p, int i, int n);
char* leerArch(const char *nomArch);

int main(void){
    char* str=NULL;
    char* subStr=NULL;
    int i=8, n=5;
    str = leerArch("frase.txt");
    subStr = subcadena(str, i, n);
    printf("Para i = %d y n = %d, Se encontro el substring: ", i,n);
    printf("%s\n", subStr);
}

char *subcadena(char *p, int i, int n){
    int e=0;
    char* arr = malloc(sizeof(char));

    p+=i;

    while (e<n){
        *(arr+e) = *p;
        p++;
        e++;
    }
    *(arr+e) = '\0';

    return arr;
}

char* leerArch(const char *nomArch){
    FILE* arch = fopen(nomArch,"r");
    int c,i = 0;
    char* arr = malloc(sizeof(char));

    while (!feof(arch)){
        c = fgetc(arch);
        arr = realloc(arr,sizeof(char)*(i+1));
        arr[i] = c;
        i++;
    }
    arr[i-1] = '\0';

    fclose(arch);

    return arr;
}