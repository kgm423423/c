#include <stdio.h>

void arrPrint(int arr[])
{
    int i;
    for(i=0;i<10;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int arr[10];
    int i,j,k,m;

    for(i=0;i<10;i++)
        scanf("%d", &arr[i]);

    for(i=1;i<10;i++)
    {
        for(j=0;j<i;j++)
        {
            if (arr[i]<=arr[j])
                {
                    m=arr[i];
                    for(k=i;k>j;k--)
                        arr[k]=arr[k-1];
                    arr[j]=m;
                }
        }

        arrPrint(arr);
    }

    arrPrint(arr);

    return 0;
}
