#include <stdio.h>

int main()
{
    int i,j,n,k;
    //printf("숫자 범위 입력 : "); scanf("%d", &n);
    //int arr[n]; 초기화가 안됌

    int arr[1000]={};//그냥 999까지

    printf("입력 횟수 입력 : "); scanf("%d", &n);

    for(i=0;i<n;i++) {
        scanf("%d", &k);
        arr[k]++;
    }
    for(i=0;i<1000;i++)
        if (arr[i]!=0)
            for(j=0;j<arr[i];j++)
                printf("%d ",i);



    return 0;
}
