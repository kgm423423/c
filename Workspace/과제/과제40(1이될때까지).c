#include <stdio.h>

int main()
{
    int n,k,c;

    scanf("%d %d",&n ,&k);

    for(c=0;n!=1;c++) {
        if (n%k==0) {
            n=n/k;
        }
        else {
            n--;
        }

    }

    printf("%d",c);


    return 0;
}
