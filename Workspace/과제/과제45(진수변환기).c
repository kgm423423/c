#include <stdio.h>

void f(int m, int n)
{
    if (n<m) {
        if (n%m>=10)
            printf("%c",55+n%m);
        else
            printf("%d",n%m);

        return;
    }

    f(m,n/m);

    if (n%m>=10)
        printf("%c",55+n%m);
    else
        printf("%d",n%m);

    return;
}

int main()
{
    int n,m;

    scanf("%d %d", &m, &n); //m은 변환 진수 n은 변환할 10진수 값

    f(m,n);

    return 0;
}
