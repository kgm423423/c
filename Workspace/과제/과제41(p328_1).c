#include <stdio.h>

void f1(int arr[])
{
    int i;

    for(i=0;i<10;i++) {
        if (arr[i]%2==1)
            printf("%d ",arr[i]);
    }

    printf("\n");

}

void f2(int arr[])
{
    int i;

    for(i=0;i<10;i++) {
        if (arr[i]%2==0)
            printf("%d ",arr[i]);
    }

    printf("\n");

}

int main()
{
    int i;
    int arr[10];

    for(i=0;i<10;i++) {
        scanf("%d",&arr[i]);
    }

    f1(arr);

    f2(arr);

    return 0;
}
