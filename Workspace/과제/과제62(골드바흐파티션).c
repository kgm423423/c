#include <stdio.h>

void f(int n)
{
    int d(int n)
    {
        if (n==2 || n==3 || n==7)
            return 1;
        else if (n%2==0 || n%3==0 || n&7==0)
            return 0;

        return 1;
    }
    int i,j;

    for(i=n/2;i>=0;i--)
        if (d(i)==1)
            for(j=i;j<=n;j++)
                if (d(j)==1 && i+j==n) {
                    printf("%d %d\n", i, j);
                    return;
                }
    return;
}

int main()
{
    int len,i;

    scanf("%d", &len);

    int nArr[len];

    for(i=0;i<len;i++)
        scanf("%d", &nArr[i]);

    for(int i=0;i<len;i++)
        f(nArr[i]);

    return 0;
}
