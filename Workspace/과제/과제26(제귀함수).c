#include <stdio.h>

int f(int i)
{
    if (i==0)
        printf("%d",i);
        return;

    f(-1);

    printf("%d",i);

    return i;
}

int main()
{
    f(10);

    return 0;
}
