#include <stdio.h>      //fin

int f(int arr[], int s, int e)
{
    int m = (s+e)/2;

    printf("%d %d %d\n", s, e, m);

    if (s==e || m==arr[m])
        return m;

    if (m < arr[m])
        return f(arr,s,m);
    else
        return f(arr,m+1,e);
}

int main()
{
    int i,j;
    int n;
    scanf("%d", &n);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    printf("%d", f(arr,0,n-1));

    return 0;
}
