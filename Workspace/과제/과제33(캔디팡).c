#include <stdio.h>

int cou;

int f(int i,int j,int arr[][7],int col)
{
    if (i<0 || i>=7 || j<0 || j>=7 || arr[i][j]==0)
        return 0;

    if (arr[i][j]==col) {
        arr[i][j]=0;
        cou++;
        f(i-1,j,arr,col);
        f(i,j-1,arr,col);
        f(i,j+1,arr,col);
        f(i+1,j,arr,col);

        return 1;
    }

    return 1;
}

int main()
{
    int i,j,num=0,arr[7][7];

    for(i=0;i<7;i++) {
        for(j=0;j<7;j++) {
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=0;i<7;i++) {
        for(j=0;j<7;j++,cou=0) {
            if (f(i,j,arr,arr[i][j])==1 && cou>=3)
                num++;
        }
    }

    printf("%d",num);

    return 0;
}
