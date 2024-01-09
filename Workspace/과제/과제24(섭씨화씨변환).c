#include <stdio.h>

float CelToFah(int i)
{
    float j = (i * 1.8) + 32;

    return j;
}

float FahToCel(int i)
{
    float j = (i - 32) / 1.8;

    return j;
}

int main()
{
    int i,j;

    scanf("%d %d",&i ,&j);

    if(j==1)
    printf("%f",CelToFah(i));

    else if(j==2)
    printf("%f",FahToCel(i));

    return 0;
}
