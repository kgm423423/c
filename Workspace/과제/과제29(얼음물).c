#include<stdio.h>

int f(int arr[][5])
{
    int i,j,num=0;

    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            if (arr[i][j]==0) {
                num++;
                s(i,j,arr);
                }
            }
        }
    }
    return num;
}

void s(int i,int j,int arr[][5])
{
    if (arr[i][j]==1)
        return;

    arr[i][j]=1;

    if (j==0)
        if(arr[i][j+1]==0){
            s(i,j+1,arr);
            printf("1 ");
        }
    else if (j==5-1)
        if(arr[i][j-1]==0){
            s(i,j-1,arr);
            printf("2 ");
        }
    else {
        if(arr[i][j-1]==0){
            s(i,j-1,arr);
            printf("3 ");
        }

        if(arr[i][j+1]==0){
            s(i,j+1,arr);
            printf("4");
        }
    }

    if (i==0)
        if(arr[i+1][j]==0)
            s(i+1,j,arr);
    else if (i==5-1)
        return;
    else {
        if(arr[i+1][j]==0)
            s(i+1,j,arr);
    }

    return;
}

int main()
{
    int arr[5][5]={0,0,0,1,1, 0,0,1,1,1, 1,1,1,1,1, 1,1,1,0,0, 0,0,0,0,0};

    printf("%d",f(arr));

    return 0;
}
