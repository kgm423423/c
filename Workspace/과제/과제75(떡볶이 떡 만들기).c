#include <stdio.h>

int n,m;

int f(int arr[], int s, int e)
{
    int k=(s+e)/2;

    if (e-s<1)
        return k-1;

    int i,sum=0;

    for(i=0;i<n;i++)
        if (arr[i]>k)
            sum+=arr[i]-k;

    if (sum==m)
        return k;

    if (sum<m)
        return f(arr,s,k-1);
    else if(sum>m)
        return f(arr, k+1, e);

}

int main()
{
    int i,j,k=0;
    scanf("%d %d", &n, &m);
    int arr[n];

    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        if (arr[i]>k)
            k=arr[i];
    }

    printf("%d",f(arr,1,k));

    return 0;
}
