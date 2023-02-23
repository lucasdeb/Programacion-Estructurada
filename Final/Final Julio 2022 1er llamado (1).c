#include <stdio.h>

//EJ T1
/*
int foo(int n,int m){
	int miFoo=1;
	if(m>0){
		miFoo=foo(n,m-1)*foo(n,m-1);
	}
	return miFoo;
}
int main(){
	printf("%d",(int)foo(0,2));
	return 0;
}
*/	
//RESPUESTA CORRECTA=1

//EJ T2
/*
int main(){
	char*s[5];int i=0;
	int*x=NULL;
	char c=2;
	s[i]=&c;
	for(i=0;i<5;i++){
		s[i]=&c;
	}
	printf("(%d,%d)",(c=='2'),(*s!=&c));
	return 0;
}
	
//RESPUESTA CORRECTA=(0,0)
*/
//EJ T3
/*
int main(){
	char*s=NULL;int i;
	char*x=(char*)malloc(sizeof(char));
	for(i=0;i<4;i++){
		*(s+i)='a'+i;
	}
	s[i]='\0';
	printf("%s",s);
	return 0;
}
	
//RESPUESTA CORRECTA->ERROR DE EJECUCION
*/
//EJ T4
/*
char foo(unsigned int w){
	unsigned int x=0;
	int i=0;
	char ar[20]="domingo";
	x=x|ar[i];
	for(i=1;ar[i]!='\0';i++){
		x=x<<8;
		x=x|ar[i];
	}
	return (x&(255<<w))>>w;
}
	
int main(){
	printf("%c",foo(24));
	return 0;
}
	
//RESPUESTA CORRECTA=i
*/
//EJ T5
/*
void sum(int*arr){
	*arr=*arr+3;
	printf("%d\n",*arr);
}
void resta(int*a){
	a=a-1;
	printf("%d\n",a);
}

int main(){
	int a[4]={3,2,13,4};
	int num=3;
	sum(a);
	resta(&num);
	printf("%d",*(a+num));
	return 0;
}
//RESPUESTA CORRECTA=4
*/

//EJ T6
/*
struct s_x{
	char c[20];
};
typedef struct s_x*t_x;

struct s_dato{
	int a[4];
	char c[20];
	int b;
	t_x x;
};
typedef struct s_dato t_dato;

int main(){
	t_dato d;
	printf("%d\n",(int)sizeof(d));
	return 0;
}
*/
	
//RESPUESTA CORRECTA=44
	
//EJ T7
/*
struct s_dato{
	char c;
	int n;
};
typedef struct s_dato*t_dato;
int main(){
	struct s_dato*p=malloc(sizeof(t_dato));
	t_dato*p2=&p;
	(*p).n=11;
	(*p2)->n=11;
	printf("%d",((*p).n)+(*p2)->n);
	return 0;
}
*/	
//RESPUESTA CORRECTA=22

//EJ T8->PREORDEN ARBOL
//EJ T9->INSERTAR EN PILA
//EJ T10->CREAR UN ARCHIVO ARCH.TXT
/*
int main(){
	int c,r;
	FILE*archT=fopen("arch.txt","w");
	fprintf(archT,"%s","Hola");
	fprintf(archT,"%s"," Mundo");
	fclose(archT);
	
	FILE*archB=fopen("arch.txt","rb");
	r=fread(&c,1,1,archB);
	while(!feof(archB)){
		printf("%c",c);
		r=fread(&c,1,1,archB);
	}
	fclose(archB);
	return 0;
}
	*/
//RESPUESTA CORRECTA=Hola Mundo
