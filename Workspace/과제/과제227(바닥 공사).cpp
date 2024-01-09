o#include <stdio.h>

int num;

int f(int i)
{
    if (i+2 <= num)
        return (f(i+2) * 2) + f(i+1);
    else
        return 1;
}

int f2(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    long long int arr[3] = {1,1,1};

    for(int i=2; i<=n; i++){
        arr[2] = (arr[0] * 2) + arr[1];
        arr[0] = arr[1];
        arr[1] = arr[2];
        printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    }

    return arr[2] % 796796;
}



int main()
{
    scanf("%d", &num);

    printf("%d", f2(num));

    return 0;
}
