#include <stdio.h>

int h,w;

void f(char arr[][h], int i, int j)
{
    if (i<0 || i>=w || j<0 || j>=h)
        return;

    if (arr[i][j]=='L') {
        arr[i][j]='.';
        f(arr,i+1,j+1);
        f(arr,i+1,j);
        f(arr,i+1,j-1);
        f(arr,i,j+1);
        f(arr,i,j-1);
        f(arr,i-1,j+1);
        f(arr,i-1,j);
        f(arr,i-1,j-1);
    }

    return;
}

int main()
{
    int i,j,sum=0;
    scanf("%d %d ", &h, &w);
    char arr[w][h];

    for(i=0;i<w;i++)
        for(j=0;j<h;j++)
           {
                scanf(" %c", &arr[i][j]);
           }

    for (i=0;i<w;i++) {
        for(j=0;j<h;j++) {
              if(arr[i][j]=='L') {
                  f(arr,i,j);
                   sum++;
            }
        }
    }

    printf("%d",sum);

    return 0;
}
