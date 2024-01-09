#include <stdio.h>

int main()
{
    int v, y, x, i, j;

    scanf("%d %d", &y, &x);
    scanf("%d %d %d", &i, &j, &v);

    int arr[y][x];

    for(i=0;i<y;i++)
        for(j=0;j<x;j++)
            scanf("%d", &arr[i][j]);




    return 0;
}
