#include <stdio.h>

int main()
{
    int i=1;
    unsigned long long int sum=0;
    unsigned int n;
    scanf("%u", &n);

    while (sum < n) {
        sum += i;
        i++;
    }
    i--;

    if (sum > n)
        i--;

    printf("%d", i);

    return 0;
}
