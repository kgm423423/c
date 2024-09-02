#include <stdio.h>

int main()
{
    int i,j;
    int n;
    scanf("%d", &n);

    for(i=1;i<n;i++) {
        for(j=n;j>i;j--)
            printf(" ");
        for(j=1;j<(i*2);j++)
            printf("*");
        printf("\n");
    }

    for(i=1;i<(n*2);i++)
        printf("*");
    printf("\n");

    for(i=n-1;i>0;i--) {
        for(j=n;j>i;j--)
            printf(" ");
        for(j=1;j<(i*2);j++)
            printf("*");
        printf("\n");
    }



    return 0;
}
