#include <stdio.h>

int main()
{

    int i,n,sum=-1;

    for(i=0;i<7;i++) {
        scanf("%d",&n);
        if (n%2==1)
            sum+=n;

    }

    if (sum!=-1)
        sum++;

    printf("%d",sum);

    return 0;
}
