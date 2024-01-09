#include <stdio.h>

int n,m,x,y;
int sum=0;

void f(int arr[n][m], int i, int j)
{
    int ii,jj;
    int k=0;

    for(ii=0;ii<y;ii++)
        for(jj=0;jj<x;jj++)
            k+=arr[ii+i][jj+j];

    if (k>sum)
        sum=k;

    return;
}

int main()
{
    int i,j,k;
    scanf("%d %d %d %d", &m, &n, &x, &y);
    int arr[n][m];

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d", &arr[i][j]);

    for(i=0;i<=n-y;i++)
        for(j=0;j<=m-x;j++)
            f(arr,i,j);

    printf("%d", sum);

    return 0;
}
