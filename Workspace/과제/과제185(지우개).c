#include <stdio.h>      //fin

int main()
{
    int i=0;
    int n;
    int m = 1;
    scanf("%d", &n);

    while(n > m) {
        m = m*2;
    }

    if (m > n)
        m=m/2;

    printf("%d", m);
}
