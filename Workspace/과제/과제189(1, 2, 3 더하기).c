#include <stdio.h>      //fin

int sum;

void f(int n)
{
    if (n < 1) {
        if (n==0)
            sum++;
        return;
    }

    f(n-3);
    f(n-2);
    f(n-1);

    return;
}

int main()
{
    int i;
    int n,m;

    scanf("%d", &n);

    for(i=0;i<n;i++) {
        sum = 0;

        scanf("%d", &m);

        f(m);

        printf("%d\n", sum);
    }

    return 0;
}
