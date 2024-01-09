#include <stdio.h>

int sum = 0;
int n;

void f(int arr[], int index, int stair, int curSum)
{
    if (index > n) {
        if (curSum > sum)
            sum = curSum;
        return;
    }

    curSum += arr[index];
    printf("%d %d %d \n",index, stair, curSum);

    if (stair < 3)
        f(arr, index+1, stair+1, curSum);

    f(arr, index+2, 0, curSum);

    return;
}

int main()
{
    int i;
    scanf("%d", &n);
    int arr[n+1];
    arr[0] = 0;

    for(i=1;i<=n;i++)
        scanf("%d", &arr[i]);

    f(arr,0,0,0);

    printf("%d", sum);

    return 0;
}
