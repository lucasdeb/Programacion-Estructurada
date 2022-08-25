#include <stdlib.h>
#include <stdio.h>
void funcion(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
int main(){
    unsigned char a='a', b='b',c='c',d='d';
    funcion(a,b,c,d);
    return 0;
}
void funcion(unsigned char a, unsigned char b, unsigned char c, unsigned char d){
    unsigned int num=0;
    num=(num|a)<<8;
    num=(num|b)<<8;
    num=(num|c)<<8;
    num=(num|d);
    printf("%d",num);
}
