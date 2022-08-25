#include <stdio.h>
#include <stdlib.h>

void operacion(int num1,int num2, char op);

int main() {
  int num1,num2;
  char op;
  
  printf("Ingresar primer numero:");
  scanf("%d",&num1);
  printf("Ingresar segundo numero:");
  scanf("%d",&num2);
  printf("Ingresar operacion [+ - * /]:");

  fflush(stdin);
  op = getchar();

  operacion(num1,num2,op);

  return 0;


}

void operacion(int num1, int num2, char op){

  int res;

  if (op == '+'){
    res = num1 + num2;
  }
  else if (op == '-'){
    res = num1 - num2;
  }
  else if (op == '*'){
    res = num1*num2;
  }
  else if (op == '/'){
    res = num1/num2;
  }
  printf("%d %c %d = %d",num1,op,num2,res);

}

  


