#include <stdio.h>      //fin
#include <math.h>

using namespace std;

int n;

bool check(int n)
{
    int i;

    if (n==1)
        return false;

    for(i=2;i<n;i++)
        if (n%i == 0)
            return false;

    return true;
}

void f(int s, int a)
{
    int i;

    if (a==n) {
        for(i=0;i<10;i++) {
            if (check(s+i)) {
                printf("%d\n", s+i);
            }
        }
        return;
    }


    for(i=0;i<10;i++) {
        if (check(s+i)) {
            f((s+i)*10, a+1);
        }
    }


    return;
}


int main()
{
    scanf("%d", &n);

    f(1,1);

    return 0;
}
