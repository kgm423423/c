#include <stdio.h>

int main()
{
    int i,j,k,a;
    int arr[5];

    for(i=0,a=0;i<5;i++) {
        scanf("%d",&arr[i]);
        a+=arr[i];
    }
    a=a/5;

    for(i=1;i<5;i++)
        for(j=0;j<5-i;j++)
            if (arr[j]<arr[j+1]) {
                k=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=k;
            }

    printf("%d\n",a); printf("%d\n",arr[2]);

    return 0;
}
