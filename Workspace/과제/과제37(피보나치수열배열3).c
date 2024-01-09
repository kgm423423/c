#include <stdio.h>

long long int arr[100]={};

long long int f(int n)
{
        if (n==0) {
            return 0;
        }
        if (n==1) {
            return 1;
        }

        if (arr[n]==0) {
            arr[n]=f(n-2)+f(n-1);
        }

        return arr[n];
}

int main()
{
    int n;

    scanf("%d",&n);

   printf("%lld",f(n-1));

    return 0;
}
