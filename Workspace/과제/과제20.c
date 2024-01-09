#include<stdio.h>

int main()
{
    int i,j,k=1,m,n,x,y;

    scanf("%d %d",&i ,&j);

    int arr[i][j];
    printf("\n");
    x=i-1;
    y=j-1;

    for(i--,j--;i>=0;i--) {
        for(n=i,m=j;n<=x && m>=0;n++,m--,k++) {
            arr[n][m]=k;
        }
    }

    for(i++,j--;j>=0;j--) {
        for(n=i,m=j;m>=0;n++,m--,k++) {
            arr[n][m]=k;
        }
    }

    for(i=0;i<=y;i++) {
        for(j=0;j<=x;j++) {
            printf("%-2d ",arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}
