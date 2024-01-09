#include <stdio.h>

void f(int arr[][5])
{
    int i,j;
    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            arr[i][j]=arr[i][j]*2;
        }
    }
    return;
}

int main()
{
    int i,j,k=1,a[5][5];

    for(i=0;i<5;i++) {
        for(j=0;j<5;j++,k++) {
            a[i][j]=k;
        }
    }

    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            printf("%-2d ",a[i][j]);
        }
        printf("\n");
    }


    printf("\n");

    f(a);

    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            printf("%-2d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
