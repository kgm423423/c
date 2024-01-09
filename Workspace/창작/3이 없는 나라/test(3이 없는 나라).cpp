#include <stdio.h>
#include <math.h>

void f1()
{



}

int getArrSize(int n)
{
    int sum = 0;

    for(int i = 0; pow(10,i) < n; i++)
        sum++;

    return sum;
}

int main()
{
    int n;

    scanf("%d", &n);
    int arrSize = getArrSize(n);
    int arr[arrSize];

    for(int i = (arrSize-1); n > 0; i--) {
        arr[i] = n % 10;
        n /= 10;
    }

    for(int i=0;i<arrSize;i++)
        printf("%d ", arr[i]);








    return 0;
}
