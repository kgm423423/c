#include <stdio.h>

int f(int i)
{
    if (i==1 || i==8)
        return 1;
    else if (i==2 || i==7)
        return 2;
    else
        return 4;
}

int main()
{
    int p, sum;
    char h;

    scanf("%c", &h);
    scanf("%d", &p);

    h-=96;

    sum+=f(h);
    sum+=f(p);

    printf("%d", sum);

    return 0;
}
