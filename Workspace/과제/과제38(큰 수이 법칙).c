#include <stdio.h>

int main()
{
    int n,m,k,i,j,p;
    scanf("%d %d %d",&n,&m,&k);
    int arr[n];

    for(i=0;i<n;i++) { //입력
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n-1;i++) { //최댓값 구하기
        for(j=0;j<n-i-1;j++) {
            if (arr[j]<arr[j+1]) {
                p=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=p;
            }
        }
    }

    printf("%d",((m-(m%k))*arr[0])+((m%k)*arr[1]));

    return 0;
}
