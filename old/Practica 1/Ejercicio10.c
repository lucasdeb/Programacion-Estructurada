#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define C 100

int cargarequipos(FILE *equipos);


int cargarequipos(FILE *equipos){
  char matriz[10][C], l;
  for (int i = 0; l != EOF; i++){
    l = fgetc(equipos);
    for (int j = 0; l != '\r' && l != EOF; j++){
      matriz[i][j] = l;
      l = fgetc(equipos);
    }
    printf("%s\n", matriz[i]);
  }
}


int main(){
  FILE *equipos;
  equipos = fopen("equipos.txt", "r");
  cargarequipos(equipos);
  return 0;
}
