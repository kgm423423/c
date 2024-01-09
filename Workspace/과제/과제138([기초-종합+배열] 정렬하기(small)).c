#include <stdio.h>      //fin

int main()
{
    int i,j;
    int n;
    scanf("%d", &n);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    for(i=1;i<n;i++) {
        for(j=0;j<n-i;j++) {
            if (arr[j] > arr[j+1]) {
                int k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }
        }
    }

    for(i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
