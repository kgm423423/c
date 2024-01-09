#include <stdio.h>

int f(long long int a, int s, int e)
{
    int k=(s+e)/2;
    long long int k1=(long long int)k*k;
    long long int k2=(long long int)(k+1)*(k+1);

    if (k1<=a && k2>a)
        return k1;
    else if (k1>a)
        return f(a, s, k-1);
    else if (k1<a)
        return f(a, k+1, e);

}

int main()
{
    int i,n;
    long long int a;

    scanf("%d", &n);

    for(i=0;i<n;i++) {
        scanf("%lld", &a);
        printf("%d\n", f(a, 1, 2000000000));
    }

    return 0;
}
