#include <stdio.h>

void binary(int arr[], int n, int s, int e, int i)
{
    if (s>e) {
        printf("찾는자료 없음, %d회 탐색", i);
        return;
    }
    int k=(s+e)/2;

    if (arr[k] == n) {
        printf("%d, %d회 탐색", k+1, i);
        return;
    }
    else if (arr[k] > n)
        binary(arr, n, s, k-1, i+1);
    else if (arr[k] < n)
        binary(arr, n, k+1, e, i+1);
}

int main()
{
    int i,n;
    int arrRang;
    scanf("%d", &arrRang);
    int arr[arrRang];
    for(i=0;i<arrRang;i++)
        scanf("%d", &arr[i]);
    scanf("%d", &n);

    binary(arr, n, 0, arrRang-1, 1);

    return 0;
}
