#include <stdio.h>

int f(int i,int j,int arr[][5])
{
    if (i<0 || i>=5 || j<0 || j>=5)
        return 0;

    if (arr[i][j]==0) {
        arr[i][j]=1;
        f(i-1,j,arr);
        f(i,j-1,arr);
        f(i,j+1,arr);
        f(i+1,j,arr);
        return 1;
    }

    return 0;
}

int main()
{
    int arr[5][5]={0,0,0,1,1, 0,0,1,1,1, 1,1,1,1,1, 1,1,1,0,0, 0,0,0,0,0};

    int i,j,num=0;

    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            if (f(i,j,arr)==1)
            {
                num++;
            }
        }
    }

    printf("%d",num);
    return 0;
}
