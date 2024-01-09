


#include <stdio.h>

int i;
int sum=100000000;

int arr[3][4] = {{1,3,5,9},{1,5,6,9},{1,5,9,11}};

void f(int r,int n)
{
    if (n>=sum)
        return;

    if (r==0 && n<sum) {
        sum=n;
        return;
    }

    int j;

    for(j=3;j>=0;j--) {
        if (arr[i][j]<=r) {
            f(r-arr[i][j],n+1);
        }
    }

    return;
}

int main()
{
    int j,k,r;
    int ii=0;

    scanf("%d", &r);

    for(i=0,k=r ; i<3 ; i++,sum=10000000,k=r,ii=0) {
        while (k >= arr[i][3]*2) {
            for(j=3;j>=0;j--)
                if (arr[i][j]<=k) {
                    k-=arr[i][j];
                    ii++;
                    break;
                }
        }
        f(k,0);

        printf("%d ",ii+sum);
    }

    return 0;
}
