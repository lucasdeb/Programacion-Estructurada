#include <stdio.h>
#include <stdlib.h>
#define TAM 100
void printbit(char bit[9],char pal[TAM]);
int main(){
    char bit[9]={0},pal[TAM]="hola";
    printbit(bit,pal);
}
void printbit(char bit[9],char pal[TAM]){
    int mask=1<<7,i,e;
    for(i=0;i<TAM && pal[i]!='\0';i++){
        for(e=0;e<8;e++){
            if(((mask>>e)&pal[i])>0){//// compara x ejemplo la h=01101000 con 1000000 desp 01000000 desp 
                printf("\n%d\n",(mask>>e)&pal[i]);
                bit[e]='1';
            }
            else{
                printf("\n");
                bit[e]='0';
            }
        }
        printf("%s ",bit);
    }
}
char *palabra(char )
