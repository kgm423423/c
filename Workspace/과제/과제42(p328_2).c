#include <stdio.h>

void f(int n)
{
    if (n<2) {
        printf("%d ",n%2);
        return;
    }

    f(n/2);

    printf("%d ",n%2);

    return;
}

int main()
{
    int n;

    scanf("%d",&n);

    f(n);

    return 0;
}
