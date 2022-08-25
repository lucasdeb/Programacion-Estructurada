#include <stdio.h>
#include <stdlib.h>
#include <math.h>
///ctes
//dec func


//estructuras
struct apunto
{
    int x;
    int y;
};
typedef struct apunto punto;
punto cargarnum();
punto cerca(punto p1,punto p2);

///main
int main(){
    punto  p1,p2,p;
    
    p1=cargarnum();
    p2=cargarnum();
    //printf("(%d,%d)",p1.x,p1.y);
    //printf("(%d,%d)",p2.x,p2.y);

    
    p=cerca(p1,p2);
    printf("el punto que esta mas lejano al (0,0) es: (%d,%d) ",p.x,p.y);
    
    return 0;
}
///funciones
punto cargarnum(){
    punto res={0,0};
    printf("ingrese cordenada x: ");
    scanf("%d",&res.x);
    printf("ingrese cordenada y: ");
    scanf("%d",&res.y);
    return res;
}
punto cerca(punto p1,punto p2){
    punto res={0,0};
    int dist1,dist2;
    dist1=(sqrt(pow(p1.x-res.x,2)+pow(p1.y-res.y,2)));
    dist2=(sqrt(pow(p2.x-res.x,2)+pow(p2.y-res.y,2)));
    if (dist1<dist2){
        return p2;
    }
    else{
        return p1;
    }

}