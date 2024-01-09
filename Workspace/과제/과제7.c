#include <stdio.h>

int main()
{
    int n,sum;

    scanf("%d",&n);

    if(n>10000)
    {
        sum=1475+(n-10000)*0.02;
    }

    else if(n>4500)
    {
        sum=1200+(n-4500)*0.05;
    }

    else if(n>1500)
    {
        sum=750+(n-1500)*0.15;
    }

    else if(n>500)
    {
        sum=350+(n-500)*0.4;
    }

    else
    {
        sum=n*0.7;
    }

    printf("%d",sum);

    return 0;
}
