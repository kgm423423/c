#include <stdio.h>      //fin 다른 케이스 확인해야함

int sum=0;
int n;

void f(int arr[], int i, int k)
{
    if (i>=n) {
        if (k>sum)
            sum=k;
        return;
    }

    f(arr,i+2,k+arr[i]);
    f(arr,i+3,k+arr[i]);

    return;
}

int main()
{
    int i;
    scanf("%d", &n);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    f(arr,0,0);

    f(arr,1,0);

    printf("%d", sum);

    return 0;
}
