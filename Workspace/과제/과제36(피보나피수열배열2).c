#include <stdio.h>

int f(int i,int arr[])
{
    if (i==0) {
        arr[i]=0;
        return 0;
    }
    if (i==1) {
        arr[i]=1;
        return 1;
    }

    arr[i]=0;

    if (arr[i]==0) {
        arr[i]=arr[i-1]+arr[i-2];
    }

    return arr[i];


}

int main()
{
    int n,i;

    scanf("%d",&n);

    int arr[n];

    for(i=0;i<n;i++) {
        printf("%d ",f(i,arr));
    }


    return 0;
}
