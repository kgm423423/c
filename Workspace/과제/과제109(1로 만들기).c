#include <stdio.h>      //fin

int sum = 100000000;

void f(int n,int k)
{
    if (k>sum)
        return;
    if (n==1) {
        sum=k;
        return;
    }

    if (n%5==0)
        f(n/5,k+1);
    if (n%3==0)
        f(n/3,k+1);
    if (n%2==0)
        f(n/2,k+1);

    f(n-1,k+1);

    return;
}

int main()
{
    int i;
    int n;
    scanf("%d", &n);

    f(n,0);

    printf("%d", sum);

    return 0;
}
