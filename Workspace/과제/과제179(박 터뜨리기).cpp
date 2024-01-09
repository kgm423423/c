#include <stdio.h>      //fin

using namespace std;

int main()
{
    int i,j;
    int n,k;
    scanf("%d %d", &n, &k);

    int s = (float)k/2 * (k+1);

    n < s ? printf("-1") : n%k == 0 ? printf("%d", k-1) : printf("%d", k);

    return 0;
}
