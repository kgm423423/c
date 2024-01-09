#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int n;
char arr[26];

void f(int i)
{
    if (i > n)
        return;

    f(i*2);
    f((i*2)+1);
    printf("%c\n", arr[i]);

    return;
}

int main()
{
    int i;
    int k = 97;

    scanf("%d", &n);

    for(i=1;i<=25;i++, k++)
        arr[i] = k;

    f(1);

    return 0;
}
