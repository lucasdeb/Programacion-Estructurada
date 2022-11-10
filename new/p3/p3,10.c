#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_texto{
    char * txt;
    int longitud;
};
typedef struct s_texto t_texto;

int cargarArrDin(char** arr);
t_texto cargarTexto();
void escribirArchTex(const char* nomArch, t_texto t);

int main(void){
    escribirArchTex("frases_con_longitud.csv", cargarTexto());
}

t_texto cargarTexto(){
    t_texto t;

    t.longitud = cargarArrDin(&(t.txt));

    printf("%s[%d]",t.txt,t.longitud);

    return t;
}

int cargarArrDin(char** arr){
    int i=0;
    char letra;
    *arr = (char*)malloc(sizeof(char));
    printf("Ingresar texto: ");
    letra = getchar();

    while (letra!='\n'){
        *((*arr) + i) = letra;
        i++;
        *arr = (char*)realloc(*arr,sizeof(char)*(i+1));
        letra = getchar();
    }
    *((*arr) + i) = '\0';

    return i;
}

void escribirArchTex(const char* nomArch, t_texto t){
    FILE* arch = fopen(nomArch,"w");

    fprintf(arch,"%d,%s",t.longitud,t.txt);

    fclose(arch);
}