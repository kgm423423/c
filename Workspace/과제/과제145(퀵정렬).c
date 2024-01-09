#include <stdio.h>

int n;

void swap(int* i,int* j)
{
    int k = *i;
    *i = *j;
    *j = k;

    return;
}

void printArr(int arr[])
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return;
}

void quickSort(int arr[],int s, int e)
{
    if (s >= e)
        return;

    printf("\n\n\ns:%d e:%d\n\n",s+1,e+1);

    int p = s;
    int i = s+1;
    int j = e;

    while (i <= j) {
        printArr(arr);
        while (arr[i] < arr[p] && i <= e)
            i++;
        while (arr[j] >= arr[p] && j >= i)
            j--;
        printf("i:%d j:%d\n",i+1,j+1);

        if (i >= j)
            swap(&arr[p], &arr[j]);
        else
            swap(&arr[i], &arr[j]);
    }

    quickSort(arr,s,j-1);
    quickSort(arr,j+1,e);

    return;
}

int main()
{
    int i;

    scanf("%d", &n);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    quickSort(arr,0,n-1);

    for(i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
