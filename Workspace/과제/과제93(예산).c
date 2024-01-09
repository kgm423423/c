#include <stdio.h>

int n;

int f(int arr[], int m, int s, int e)
{
    int i;
    int sum=0;

    if (s>e)
        return e;
    int p=(s+e)/2;

    for(i=0;i<n;i++) {
        if (arr[i]>p)
            sum+=p;
        else
            sum+=arr[i];
    }

    if (sum == m)
        return p;
    else if (sum > m)
        return f(arr, m, s, p-1);
    else if (sum < m)
        return f(arr, m, p+1, e);

}


int main()
{
    int i;
    int m;
    int k=0;
    scanf("%d", &n);
    int arr[n];
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        if (arr[i]>k)
            k=arr[i];
    }
    scanf("%d", &m);

    printf("%d", f(arr, m, 0, k));

    return 0;
}
