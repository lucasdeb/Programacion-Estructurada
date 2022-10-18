#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NA 15

typedef struct{
char nombre[100];
int legajo, materias[30];
}
t_alumno;

typedef struct{
char nombre[100];
int codigo;
}
t_materia;

typedef struct{
int legajo_alumno;
int cod_materia,nota;
}
t_nota;

typedef t_alumno a;

void cargarArchAlum();

int main(void){
    cargarArchAlum();
}

void cargarArchAlum(){
    a arr[NA] = {0};
    int i = 0,j = 0;
    FILE* arch = fopen("alumnos.txt","w");

    printf("Ingresar Legajo: ");
    scanf("%d",&arr[i].legajo);

    while (i<NA-1 && arr[i].legajo!=0){
        fflush(stdin);
        printf("Ingresar Nombre: ");
        scanf("%s",&arr[i].nombre);
        fflush(stdin);
        printf("Ingresar codigo de la materia: ");
        scanf("%d",&arr[i].materias[j]);

        for (j = 1; j < 30 && arr[i].materias[j]!=0; j++){
            printf("Ingresar codigo de la materia: ");
            scanf("%d",&arr[i].materias[j]);
        }
        fprintf(arch,"%d,%s",arr[i].legajo,arr[i]);
        for (j = 0; i < count; i++)
        {
            /* code */
        }
        
        i++;
        if(i<NA){
            printf("Ingresar Legajo: ");
            scanf("%d",&arr[i].legajo);
        }
    }
}