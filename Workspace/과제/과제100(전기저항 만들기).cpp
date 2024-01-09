#include <stdio.h>

int i;
int sum=100000000;

int arr[3][4] = {{1,3,5,9},{1,5,6,9},{1,5,9,11}};

void f(int r,int n)
{
    if (r==0) {
        if (n<sum)
            sum=n;
        return;
    }

    int j;

    for(j=0;j<4;j++) {
        if (arr[i][j]<=r) {
            f(r-arr[i][j],n+1);
        }
    }

    return;
}

int main()
{
    int j;
    int r;

    scanf("%d", &r);

    for(i=0;i<3;i++,sum=10000000) {
        f(r,0);
        printf("%d ",sum);
    }

    return 0;
}
