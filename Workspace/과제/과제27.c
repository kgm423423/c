#include <stdio.h>


void f(j,i,arr[][5])
{
    if (j==0) {
        if (i==0) {
            if (arr[j+1][i]==1 && arr[j][i+1]==1)
                break;
        }
        else if(i==5-1) {
            if (arr[j+1][i]==1 && arr[j][i-1]==1)
                break;
        }
        else {
            if (arr[j+1][i]==1 && arr[j][i+1]==1 && arr[j][i-1]==1)
                break;
        }
    }
    else if(j==5-1) {
        if (i==0) {
            if (arr[j-1][i]==1 && arr[j][i+1]==1)
                break;
        }
        else if(i==5-1) {
            if (arr[j-1][i]==1 && arr[j][i-1]==1)
                break;
        }
        else {
            if (arr[j-1][i]==1 && arr[j][i+1]==1 && arr[j][i-1]==1)
                break;
        }
    }
    else {
        if (i==0) {
            if (arr[j+1][i]==1 && arr[j][i+1]==1 && arr[j-1][i]==1)
                break;
        }
        else if(i==5-1) {
            if (arr[j+1][i]==1 && arr[j][i-1]==1 && arr[j-1][i])
                break;
        }
        else {
            if (arr[j+1][i]==1 && arr[j][i+1]==1 && arr[j][i-1]==1 && arr[j-1][i])
                break;
        }
    }

    if (j==0) {
        f(j+1,i);
    }
    else if(j==5-1) {
        f(j-1,i);
    }
    else {
        f(j+1,i);
        f(j-1,i);
    }

    if (i==0) {
        f(j,i+1);
    }
    else if(i==5-1) {
        f(j,i-1);
    }
    else {
        f(j,i+1);
        f(j,i-1);
    }

    arr[j][i]==1

    break;
}

int main()
{
    int arr[5][5]={{0,1,1,0,0},{1,0,0,0,1},{0,0,1,1,1},{1,1,1,0,0},{0,0,0,1,1}},i,j,k=0;

    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            if (arr[j][i]==0) {
                f(j,i,arr);
                k++
            }
        }
    }

    return 0;
}
