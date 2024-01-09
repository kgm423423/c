#include <stdio.h>

int main()
{
    int i,j,n,m; //n은 나누는 용 m은 숫자개수
    char k; //판별 변수
    scanf("%d", &m);
    int arr[m];

    for(i=0;i<m;i++) {
        scanf("%d", &arr[i]);
        if (i==0)
            n=arr[i];
        if (arr[i]<n)
            n=arr[i];
    }

    for(k=0;n>0;n--,k=0) {
        for(j=0;j<m;j++) {
            if (arr[j]%n!=0) {
                k=1;
                break;
            }
        }
        if (k==0)
            break;
    }

    printf("%d", n);

    return 0;
}
