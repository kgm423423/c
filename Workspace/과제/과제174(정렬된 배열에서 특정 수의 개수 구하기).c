#include <stdio.h>      //fin

int n;

int f1(int arr[], int s, int e)
{
    int m = (s+e)/2;

    if (s>=e)
        return m;

    if (arr[m] >= n)
        return f1(arr,s,m);
    else
        return f1(arr,m+1,e);
}

int f2(int arr[], int s, int e)
{
    int m = (s+e)/2;

    if (s>=e)
        return m;

    if (arr[m] > n)
        return f2(arr,s,m);
    else
        return f2(arr,m+1,e);
}

int main()
{
    int i;
    int arrLen;
    scanf("%d %d", &arrLen, &n);
    int arr[arrLen];

    for(i=0;i<arrLen;i++)
        scanf("%d", &arr[i]);

    int n1 = f1(arr,0,(arrLen-1));
    int n2 = f2(arr,0,(arrLen-1));

    if (arr[n1] != n)
        printf("-1");
    else {
        if (arr[n2] != n)
            n2--;
        printf("%d", (n2-n1)+1);
    }

    return 0;
}
