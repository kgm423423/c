#include <stdio.h>      //fin
#include <algorithm>

using namespace std;

int n, m;

void QuickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int i = s;
    int j = e;

    while (i < j) {
        while (i < n && arr[s] >= arr[i])
            i++;
        while (arr[s] < arr[j])
            j--;

        if (i < j) {
            swap(arr[i], arr[j]);
        }
        else {
            swap(arr[s], arr[j]);
        }
    }

    QuickSort(arr, s, j-1);
    QuickSort(arr, j+1, e);

    return;
}

int BinarySearch(int arr[], int s, int e)
{
    int p = (s+e)/2;
    int sum = 0;

    if (s >= e) {
        for(int i=0;i<n;i++) {
            if (arr[i] > s)
                sum += s;
            else
                sum += arr[i];
        }

        //printf("함수 종료 \n %d %d \n\n", s, sum);

        if (sum > m)
            return s-1;
        else
            return s;
    }

    for(int i=0;i<n;i++) {
        if (arr[i] > p)
            sum += p;
        else
            sum += arr[i];
    }

    //printf(" %d    sum : %d\n", p, sum);

    if (sum > m)
        return BinarySearch(arr, s, p-1);
    else if (sum < m)
        return BinarySearch(arr, p+1, e);
    else
        return p;
}

int main()
{
    scanf("%d", &n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    scanf("%d", &m);

    QuickSort(arr, 0, n-1);
    int sum = BinarySearch(arr, 0, arr[n-1]);

    printf("%d", sum);

    return 0;
}
