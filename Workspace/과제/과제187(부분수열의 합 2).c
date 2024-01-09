#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int n,m;
    int sum = 0;

    scanf("%d %d", &n, &m);

    int arr[i+1];
    arr[0] = 0;

    for(i=1;i<=n;i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i-1];
    }

    for(i=1;i<=n;i++) {
        for(j=i;j<=n;j++) {
            if (abs(arr[i] - arr[j]) == m)
                sum++;
        }
    }

    printf("%d", sum);

    return 0;
}
