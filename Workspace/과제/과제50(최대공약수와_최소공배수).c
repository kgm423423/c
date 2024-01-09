#include <stdio.h>

int main()
{
    int k,m,n;

    scanf("%d %d", &m, &n);
    if (m>n)
        k=n;
    else
        k=m;

    for(;k>1;k--) {
        if (m%k==0 && n%k==0) {
            m=m/k;
            n=n/k;
            break;
        }
    }

    printf("%d\n",k); printf("%d\n",k*m*n);

    return 0;
}
