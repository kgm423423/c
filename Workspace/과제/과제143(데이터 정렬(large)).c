#include <stdio.h>      //fin

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int p = s;
    int i=p+1,j=e;

    while (j >= i) {
        while ((arr[p] >= arr[i]) && (i <= e))
            i++;
        while ((arr[p] < arr[j]) && (j >= i))
            j--;

        if (j < i) {
            int k = arr[p];
            arr[p] = arr[j];
            arr[j] = k;
        }
        else {
           int k = arr[i];
            arr[i] = arr[j];
            arr[j] = k;
        }
    }

    quickSort(arr,s,j-1);
    quickSort(arr,j+1,e);

    return;
}

int main()
{
    int i;
    int n;
    scanf("%d", &n);
    int  arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    quickSort(arr,0,n-1);

    for(i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
