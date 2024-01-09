#include <stdio.h>      //fin
#include <iostream>

using namespace std;

int main()
{
    int n,m;

    scanf("%d %d", &n, &m);

    bool check[m+1];

    for(int i=0;i<=m;i++) {
        check[i] = false;
    }
    check[1] = true;

    for(int i=2;i<=m;i++) {
        if (!check[i]){
            int j = i+i;

            while (j <= m) {
                check[j] = true;
                j += i;
            }
        }
    }

    for(int i=n; i<=m; i++)
        if (!check[i])
            printf("%d\n", i);

    return 0;
}
