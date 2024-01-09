#include <stdio.h>
#include <iostream>

using namespace std;

int n,m;

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int i=(s+1);
    int j=e;

    while (i <= j) {
        while (i < n && arr[i] <= arr[s])
            i++;
        while (arr[j] > arr[s])
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
        else
            swap(arr[s], arr[j]);
    }

    quickSort(arr,s,j-1);
    quickSort(arr,j+1,e);

    return;
}

int main()
{
    int i,j;
    int sum = 0;
    scanf("%d %d", &n, &m);
    int arr[n];

    //배열 입력받기
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    //정렬
    quickSort(arr, 0, n-1);

    i=0; j=n-1;
    while (i<j) {
        if (arr[i] + arr[j] > m)
            j--;
        else {
            if (arr[i] + arr[j] == m)
                sum++;
            i++;
        }
    }

    printf("%d", sum);

    return 0;
}
