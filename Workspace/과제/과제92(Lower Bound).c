#include <stdio.h>

int arrRang;

int f(int arr[], int t, int s, int e)
{
    int n = (s+e)/2;

    printf("target : %d\n", n+1);

    if (s>e) {
        if (e == arrRang-1)
            return n+2;
        else
            return n+1;
    }

    if (arr[n]<t && arr[n+1]>=t)
        return n+2;
    else if (arr[n]>=t)
        return f(arr, t, s, n-1);
    else if (arr[n]<t)
        return f(arr, t, n+1, e);
}

int main()
{
    int i;
    int t;
    scanf("%d %d", &arrRang, &t);
    int arr[arrRang];
    for(i=0;i<arrRang;i++)
        scanf("%d", &arr[i]);

    printf("%d", f(arr, t, 0, arrRang-1));

    return 0;
}
