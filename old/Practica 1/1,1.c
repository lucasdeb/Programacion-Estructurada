#include <stdio.h>
#include <stdlib.h>

int main() {
  int redondeo,piso,techo;
  float num;
  printf("Ingresar numero real:");
  scanf("%f",&num);
  float e = num - (int)num;
  int inum = (int)num;
  if (e==0) {
    piso = inum;
    techo = inum;
    redondeo = inum;
  }
  else if (e>=0.5){
    piso = inum;
    techo = inum+1;
    redondeo = inum+1;
  }
  else {
    piso = inum;
    techo = inum+1;
    redondeo = inum;
  }

  printf("Piso: %d Techo: %d Redondeo: %d",piso,techo,redondeo);
  return 0;
} 