#include <stdio.h>

void f(int n)
{
    int i,arr[3]={1,1,100};

    for(i=0;i<n;i++) {
        printf("확인 %d\n",arr[2]);

        if (i<3) {
            printf("%d ",arr[i]);
        }
        else {
             arr[2]=arr[0]+arr[1]; //배열이 안더해짐
             printf("%d ",arr[2]);
             arr[0]=arr[1];
             arr[1]=arr[2];
        }
    }

    return;
}

int main()
{
    int n;

    scanf("%d",&n);

    f(n);

    return 0;
}
