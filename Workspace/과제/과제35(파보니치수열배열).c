#include <stdio.h>

int main()
{
    int n,i;
    long long int arr[3]={0,1};

    scanf("%d",&n);

    for(i=0;i<n;i++) {
        if (i<2) {
            printf("%lld \n",arr[i]);
        }
        else {
             arr[2]=arr[0]+arr[1];
             printf("%lld \n",arr[2]);
             arr[0]=arr[1];
             arr[1]=arr[2];
        }
    }

    return 0;
}
