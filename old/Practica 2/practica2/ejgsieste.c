#include <stdlib.h>
#include <stdio.h>
/////////ctes
///matematica 1
////lengua 2
///computacion 3
////ingles 4
///contabilidad 5
////fisica 6
#define na 12
#define nm 20
#define lchar 100
#define lint 30
///////estruc
typedef struct{
char nombre[lchar];
int legajo, materias[lint];
}
t_alumno;
typedef struct{
char nombre[lchar];
int codigo;
}
t_materia;
typedef struct
{
int legajo_alumno;
int cod_materia,nota;
}
t_nota;
typedef t_alumno alumno;
typedef t_materia materia;
typedef t_nota notas;
///////////funciones
int estaenarreglo(int arreglo[lint],int num);
FILE* abrirarch(char nombre[lchar],char modo[]);
void cargarestrucalumnos(alumno arralu[na]);////carga la estructura
void cargararchalu(alumno arralu[na],FILE* arch);/////imprime la estructura en un archivo aparte
void cargarestrucmaterias(materia arrmat[na]);
void cargarARCHmat(materia arrmat[nm],FILE* arch);
///////funcion principal
int main(){
    alumno arralu[na]={0,0,0};
    materia arrmat[nm]={0,0};
    FILE* arch;
    ////ejer 1
    //cargarestrucalumnos(arralu);
    //arch=abrirarch("alumnos.txt","w");
    //cargararchalu(arralu,arch);
    //fclose(arch);
    ///ej2
    /*cargarestrucmaterias(arrmat);
    arch=abrirarch("materias.txt","w");
    cargarARCHmat(arrmat,arch);
    fclose(arch);*/
    ///ej3 agregar alumnos
    /*cargarestrucalumnos(arralu);
    arch=abrirarch("alumnos.txt","a");
    cargararchalu(arralu,arch);
    fclose(arch);*/
    ///ej4 agregar mas mayterias
    /*cargarestrucmaterias(arrmat);
    arch=abrirarch("materias.txt","a");
    cargarARCHmat(arrmat,arch);
    fclose(arch);*/
    return 0;
}
/////////funciones
FILE* abrirarch(char nombre[lchar],char modo[]){
    return fopen(nombre,modo);
}
int estaenarreglo(int arreglo[lint],int num){
    int i,res=0;
    for(i=0;arreglo[i]!=0;i++){
        if (num==arreglo[i]){
            res=1;
        }
    }
    return res;
}
///////parte 1 CARGAR DATOS EN ARCHIVOS////////////
/////1.0 PARA LOS ALUMNOS
void cargarestrucalumnos(alumno arralu[na]){
    int lega,fila=0,contchar=0,contint=0,materia,arrlegajos[lint]={0};
    char letra={0};
    printf("ingrese el legajo del alumno %d: ",fila);
    scanf("%d",&lega);
    while (lega!=0 && fila<na-1 && (estaenarreglo(arrlegajos,lega)==0)){
        contchar=0;
        contint=0;
        printf("ingrese nombre alumno:\n");
        fflush(stdin);
        letra=getchar();
        letra=getchar();
        while(contchar<lchar-1 && letra!='\n' && letra!='\t'){
            arralu[fila].nombre[contchar]=letra;
            fflush(stdin);
            letra=getchar();
            contchar++;
        }
        arralu[fila].nombre[contchar]='\0';
        printf("ingrese codigo materia Numero %d: ",contint);
        scanf("%d",&materia);
        while(contint<lint-1 && materia!=0 && (estaenarreglo(arralu[fila].materias,materia)==0)){
            arralu[fila].materias[contint]=materia;
            scanf("%d",&materia);
            contint++;
        }
        arralu[fila].materias[contint]=0;
        arralu[fila].legajo=lega;
        arrlegajos[fila]=lega;
        fila++;
        if (lega!=0){
            printf("ingrese el legajo del alumno %d: ",fila);
            scanf("%d",&lega);
        }
    }
    arralu[fila].legajo=0;

}
void cargararchalu(alumno arralu[na],FILE* arch){
    int i,j;
    for(i=0;arralu[i].legajo!=0;i++){
        fprintf(arch,"%d,%s",arralu[i].legajo,arralu[i].nombre);
        for(j=0;arralu[i].materias[j]!=0;j++){
            fprintf(arch,",%d",arralu[i].materias[j]);
        }
        fprintf(arch,"%c",'\n');

    }
}
/////1.1 PARA LAS  MATERIAS
void cargarestrucmaterias(materia arrmat[nm]){
    int contchar=0,fila=0,codigomat,arrcodmat[nm]={0};
    char letra;
    printf("ingrese codigo de la materia n %d:",fila);
    scanf("%d",&codigomat);
    while( codigomat!=0 && fila<nm-1 && estaenarreglo(arrcodmat,codigomat)==0){
        contchar=0;
        printf("ingrese nombre de la materia: ");
        fflush(stdin);
        letra=getchar();
        letra=getchar();
        while(contchar<lchar-1 && letra!='\n' && letra!='\t'){
            arrmat[fila].nombre[contchar]=letra;
            fflush(stdin);
            letra=getchar();
            contchar++;
        }
        arrmat[fila].nombre[contchar]='\0';
        arrmat[fila].codigo=codigomat;
        fila++;
        if (codigomat!=0){
            printf("ingrese codigo de la materia n %d:",fila);
            scanf("%d",&codigomat);     
        }
       
    }
    arrmat[fila].codigo=0;

}
void cargarARCHmat(materia arrmat[nm],FILE* arch){
    int i;
    for(i=0;arrmat[i].codigo!=0;i++){
        fprintf(arch,"%d,%s\n",arrmat[i].codigo,arrmat[i].nombre);

    }
}
//////////////////////////////////////////LEEER ARCHIVOS//////////////////////////////
void leerarchivo(FILE* arch , alumno arralu[na]){
    
}
//////////////////////1.2 NOTAS
void cargarARCHnotas(alumno arralu[na],materia arrmat[nm], FILE* arch){
    int fila,contmat,codigomateria,conttot=0,ubicacion;
    notas arrnotas[100];
    for(fila=0;arralu[fila].legajo!=0;fila++){
        for(contmat=0;arralu[fila].materias[contmat]!=0;contmat++){
            arrnotas[conttot].legajo_alumno=arralu[fila].legajo;
            arrnotas[conttot].cod_materia=arralu[fila].materias[contmat];
            printf("ingrese la nota de %s para la materia ",arralu[fila].nombre);
            ubicacion=encontrarubic(arrmat,arralu[fila].materias[contmat]);
            if(ubicacion>=0){
                printf("%s: ",arrmat[ubicacion].nombre);
            }
            conttot++;

        }
    }
    
}
/////cosas que necesito de cada arreglo
///notas materia xara cada alumno
////unir los codigos de materias del alumno con EL NOMBRE DE KA MATERIA
///puedo hacrr q compare y me decuelva la posicion y enbase a eso depsues en la funcion lo pongo 
///paso una variablechar y tengo q imprimir los cosos 0,1 que tenga eso
int encontrarubic(materia arrmateria[nm],int codigo){
    int i,posicion=-1;
    for(i=0; arrmateria[i].codigo!=0;i++){
        if (codigo==arrmateria[i].codigo){
            posicion=i;
        }
    }
    return posicion;
}