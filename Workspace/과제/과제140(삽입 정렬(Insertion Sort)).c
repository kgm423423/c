#include <stdio.h>

int main()
{
    int i,j,k;
    int n;
    scanf("%d", &n);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    for(i=1;i<n;i++) {
        for(j=0;j<i;j++) {
            if (arr[j] > arr[i]) {
                int p = arr[i];
                printf("%d\n", j+1);
                for(k=i;k>j;k--)
                    arr[k] = arr[k-1];
                arr[j] = p;
            }
        }
    }

    return 0;
}
