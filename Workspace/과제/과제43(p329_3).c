#include <stdio.h>

void f(int arr[])
{
    int i,n,o,t;

    for(i=0,o=0,t=0;i<10;i++) {
        scanf("%d",&n);
        if (n%2==1) {
            arr[o]=n;
            o++;
        }
        else {
            arr[10-t-1]=n;
            t++;
        }
    }

    for(i=0;i<10;i++) {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[10];

    f(arr);

    return 0;
}
