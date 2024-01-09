#include <stdio.h>
#include <algorithm>

using namespace std;

int n,m;


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

int main()
{
    int i;
    int x,y;

    int p = 0;
    int sum = 0;

    scanf("%d %d", &n, &m);

    int arr[n];

    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        p += arr[i];
    }

    p = p/m;

    printf("p : %d\n", p);

    QuickSort(arr, 0, n-1);

    i = 0;  x = 0;  y = 0;

    while (i < n) {
        y = x + arr[i];

        if (y > p) {
            if (x > sum)
                sum = x;
            printf("x : %d\n", x);
            x = 0;
        }
        else {
            x = y;
            i++;
        }
    }
    if (y > sum)
        sum = y;
    printf("y : %d\n", y);

    printf("%d", sum);

    return 0;
}
