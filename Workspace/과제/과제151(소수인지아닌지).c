#include <stdio.h>      //fin
#include <iostream>

using namespace std;

int main()
{
    int m,n;
    int i,j;

    scanf("%d %d",&m, &n);
    bool arr[n+1] = {};

    for(i=2;i<=n;i++) {
        if (arr[i] == false) {

            j=i;
            while (j+i <= n) {
                j += i;
                arr[j] = true;
            }
        }
    }

    if (m==1)
        m++;

    for(;m<=n;m++)
        if (arr[m]==false)
            printf("%d\n", m);

    return 0;
}
