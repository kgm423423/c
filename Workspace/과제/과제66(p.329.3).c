#include <stdio.h>

void f(int arr[])
{
    int i,n=0,m=10-1,k;

    for(i=0;i<10;i++) {
        scanf("%d", &k);

        if (k%2==0) {
            arr[m]=k;
            m--;
        }
        else {
            arr[n]=k;
            n++;
        }

    }

    return;
}

void printArr(int arr[])
{
    int i;

    for(i=0;i<10;i++)
        printf("%d ", arr[i]);

    return;
}

int main()
{
    int arr[10];

    f(arr);
    printArr(arr);

    return 0;
}
