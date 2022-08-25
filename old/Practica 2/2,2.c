#include <stdio.h>
#include <stdlib.h>

struct puntos
{
    int x;
    int y;
};
typedef struct puntos punto;

void leer(struct puntos punto[10]);
void consecutivos(struct puntos punto[10]);

void main(){
    struct puntos punto[10];
    leer(punto);  
}

void leer(struct puntos punto[10]){
    
    FILE* f = fopen("/Users/lucasdebarbieri/Library/CloudStorage/OneDrive-UCA/ProgramacionE/Practica 2/puntos.csv", "r");
    for (int i = 0; i < 10; ++i){
        struct puntos p;
        fscanf(f, "%d,%d,", &p.x, &p.y);
        punto[i] = p;
    }
}

void consecutivos(struct puntos punto[10]){
    float dmin;
    for (int i = 0; i < 10; i++){
        for (int x = i+1; x < 10; x++){
            if punto[i].x
        }
        
    }
    
}

// recursive function to find the minimum distance between two points
float minDistance(struct puntos punto[10], int i, int j)
{
    // base case
    if (i == j)
        return 0;
 
    // if j is greater than i, swap them
    if (j > i)
    {
        int temp = j;
        j = i;
        i = temp;
    }
    // initialize minimum distance as infinite
    float dmin = (float)INT_MAX;
 
    // traverse all points after the start point
    for (int k = i + 1; k < j; k++)
    {
        // Find the distance between point k and the start point
        float d = minDistance(punto, i, k) +
                  minDistance(punto, k, j) +
                  dist(punto[i], punto[j]);
 
        // Update dmin if smaller distance is found
        if (d < dmin)
            dmin = d;
    }
    // return minimum distance
    return dmin;
}


