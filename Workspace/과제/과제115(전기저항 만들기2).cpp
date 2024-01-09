#include <stdio.h>      //시간초과

int i;
int sum=100000000;

int arr[4] = {1,5,6,9};

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
        if (arr[j]<=r) {
            f(r-arr[j],n+1);
        }
    }

    return;
}

int main()
{
    int i=0;
    int j;
    int r;

    scanf("%d", &r);

    f(r,0);

    printf("%d ",sum);

    while (r != 0) {
        for(j=3;j>=0;j--)
            if (arr[j]<=r) {
                r-=arr[j];
                i++;
                break;
            }
    }

    printf("%d", i);

    return 0;
}
