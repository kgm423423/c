#include <stdio.h>      //fin

int main()      //8:00
{
    int i,j;
    int n;
    scanf("%d",&n);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<n-1;i++) {
        for(j=j+1;j<n;j++) {
            if (arr[i] > arr[j]) {
                int k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }

    printf("%d",arr[(n/2)-1]);

    return 0;
}
