#include <stdio.h>

int n,m;

int f(int arr[], int p, int s, int e)
{
    if (s>e)
        return k+1;
    int k=(s+e)/2;

    if (arr[k-1]<=p && arr[k]>p)
        return k;
    else if (arr[k-1]>=p)
        return f(arr,p,s,k-1);
    else if (arr[k-1]<p)
        return f(arr,p,k+1,e);
}

int main()
{
    int i;
    scanf("%d %d", &n, &m);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    printf("%d", f(arr,m,1,n));

    return 0;
}
