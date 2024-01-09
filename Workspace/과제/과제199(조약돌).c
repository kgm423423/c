#include <stdio.h>

int sum = 999999999;
int n;


void copyArr(int arr[], int arr2[])
{
    int i;

    for(i=0;i<n;i++)
        arr2[i] = arr[i];

    return;
}

void f(int arr[], int index, int curSum)
{
    if (index == n) {
        if (curSum < sum)
            sum = curSum;
        return;
    }

    if (arr[index] == 0) {
        f(arr, index+1, curSum);
        return;
    }

    if (arr[index] <= arr[index+2] && arr[index] <= arr[index+1]) {
        int arr2[n+2];
        copyArr(arr, arr2);

        arr2[index+2] -= arr2[index];
        arr2[index+1] -= arr2[index];
        f(arr2, index+1, curSum+1);
    }

    if (arr[index] <= arr[index+1]) {
        int arr3[n+2];
        copyArr(arr, arr3);

        arr3[index+1] -= arr3[index];
        f(arr3, index+1, curSum+1);
    }

    int arr4[n+2];
    copyArr(arr, arr4);
    f(arr4, index+1, curSum+1);

    return;
}

int main()
{
    int i;
    scanf("%d", &n);
    int arr[n+2];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    f(arr,0,0);

    printf("%d",sum);



    return 0;
}
