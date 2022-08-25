#include <stdio.h>
int main()
{
    int i = 0, j = 0;
    int *p1, *p2;
    p1 = &i;
    p2 = &j;
    scanf("%d", p1);
    scanf("%d", &j);
    printf("i: %2d - j: %2d\n", i, j);
    p2 = p1;
    (*p2)++;
    printf("i: %2d - j: %2d\n", i, j);
    return 0;
}