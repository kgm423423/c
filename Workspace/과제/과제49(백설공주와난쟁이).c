#include <stdio.h>

int main()
{
    int i,j,k;
    int arr[7];

    for(i=0;i<7;i++)
        scanf("%d", &arr[i]);

    for(i=1;i<7;i++)
        for(j=0;j<7-i;j++)
            if (arr[j]<arr[j+1]) {
                k=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=k;
            }
    printf("%d\n",arr[0]); printf("%d\n",arr[1]);

    return 0;
}
