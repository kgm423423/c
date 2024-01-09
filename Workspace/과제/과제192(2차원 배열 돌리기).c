#include <stdio.h>      //fin

const int n = 3;

void f(int arr[n][n])
{
    int i,j;
    int ii,jj;

    int arr2[n][n];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr2[i][j] = arr[i][j];


    for(i=0;i<n;i++)
        for(j=n-1,jj=0;j>=0;j--,jj++)
            arr[i][jj] = arr2[j][i];

    return;
}

int main()
{
    int i,j;
    int a;

    int arr[n][n];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &arr[i][j]);

    scanf("%d", &a);

    a = a%4;

    for(i=0;i<a;i++)
        f(arr);

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }


    return 0;
}
