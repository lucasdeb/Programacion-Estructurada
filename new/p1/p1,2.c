#include <stdlib.h>
#include <stdio.h>

void operacion(int n1, int n2, char op);

void operacion(int n1, int n2, char op){
    int resultado;
    if (op == '+'){
        resultado = n1 + n2;
    }
    else if (op == '-'){
        resultado = n1 - n2;
    }
    else if (op == '*'){
        resultado = n1 * n2;
    }
    else if (op == '/'){
        resultado = n1 / n2;
    }

    printf("%d %c %d = %d\n", n1, op, n2, resultado);
}

void main(){
    int n1,n2;
    char op;
    printf("Ingrese un numero: ");
    scanf("%d", &n1);
    printf("Ingrese otro numero: ");
    scanf("%d", &n2);
    printf("Ingrese una operacion [+,-,*,/]: ");
    fflush(stdin);
    op = getchar();
    operacion(n1, n2, op);


}