#include <stdio.h>      //fin

const int INF = 999999999;

int main()
{
    int i,j,k;
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[n][n];
    int sum = INF;
    int ii;

    //배열 초기화
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr[i][j] = INF;

    //i==j=0
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if (i==j)
                arr[i][j] = 0;

   //관계 입력
    for(k=0;k<m;k++) {
        scanf("%d %d", &i, &j);
        arr[i-1][j-1] = 1;
        arr[j-1][i-1] = 1;
    }

    //플로이드 워셜 알고리즘
    for(k=0;k<n;k++) {
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++)
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
        }
    }

    //출력
    for(i=0;i<n;i++) {
        k=0;
        for(j=0;j<n;j++)
            k += arr[i][j];
        if (sum > k) {
            sum = k;
            ii = i;
        }
    }

    printf("%d", ii+1);

    return 0;
}
