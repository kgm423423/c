#include <stdio.h>      //시간초과 fin

int main()
{
    int i,j;
    int n;

    scanf("%d", &n);

    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    for(i=0;i<n;i++) {
        j=i+1;

        while (j<n && arr[i] >= arr[j])
            j++;

        if (j>=n)
            printf("-1 ");
        else
        printf("%d ", arr[j]);
    }


    return 0;
}
