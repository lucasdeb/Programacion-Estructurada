#include <stdio.h>

void main(){
    char a = 'a';
    char *p = &a;
    char **pp = &p;

    printf("%c\n",*p);
    printf("%c\n",**pp);
    printf("%d\n",&a);
    printf("%d\n",p);
}