#include <stdio.h>

int n,m;

int sum=100000000;

void f(int arr[], int k, int i)
{
    if (i>sum)
        return;
    if (k==m) {
        sum=i;
        return;
    }
    if (k>m)
        return;

    int ii;

    for(ii=n-1;ii>=0;ii--) {
        f(arr,k+arr[ii],i+1);
    }

    return;
}

int main()
{
    int i;
    scanf("%d %d", &n, &m);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    f(arr,0,0);

    if (sum==100000000)
        printf("-1");
    else
        printf("%d", sum);

    return 0;
}
