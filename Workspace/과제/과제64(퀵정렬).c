#include <stdio.h>

void chan(int *i, int *j)
{
    int k;
    k=*i;
    *i=*j;
    *j=k;
    return;
}

void printArr(int arr[], int s, int e)
{
    int i;

    for(i=s-1;i<e;i++)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}

void f(int arr[], int s, int e)
{
    if (s>=e) {
        printf("배열길이 %d %d 함수탈출\n", s, e);
        return;
    }

    int i=s, j=e-1;

    while(i<j)
    {
        while(arr[s-1]>arr[i] && i<e-1)
            i++;

        while(arr[s-1]<arr[j] && j>s-1)
            j--;

        printArr(arr, s, e);
        printf("%d %d\n",i+1 ,j+1);

        if (i>=j)
            break;

        chan(&arr[i], &arr[j]);
    }
    chan(&arr[s-1], &arr[j]);
    printArr(arr, s, e);
    printf("\n");

    f(arr, s, j);
    f(arr, j+2, e);

    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    printf("\n");

    f(arr, 1, n);

    printArr(arr, 1, n);

    return 0;
}
