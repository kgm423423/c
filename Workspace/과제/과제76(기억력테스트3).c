#include <stdio.h>

int f(int arr[], int n, int s, int e)
{
    if (s>e)
        return -1;

    int k=(s+e)/2;

    if (n==arr[k-1])
        return k;
    else if (arr[k-1]>n)
        return f(arr,n,s,k-1);
    else if (arr[k-1]<n)
        return f(arr,n,k+1,e);
}

int main()
{
    int i,k;
    int n,m;
    scanf("%d", &n);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    scanf("%d", &m);

    for(i=0;i<m;i++) {
        scanf("%d", &k);
        printf("%d ", f(arr,k,1,n));
    }

    return 0;
}
