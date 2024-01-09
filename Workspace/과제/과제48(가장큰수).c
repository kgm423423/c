#include <stdio.h>

int main()
{
    int i,n,o=0,e=0;

    for(i=0;i<7;i++)
    {
        scanf("%d", &n);

        if (n%2==1 && n>o)
            o=n;

        if (n%2==0 && n>e)
            e=n;
    }

    printf("%d",o+e);

    return 0;
}
