#include <stdio.h>      //fin

const int INF = 999999999;

int main()
{
    int i,j,k;
    int n;
    char d;
    scanf("%d", &n);
    int arr[n][n];
    int arr2[n][n];

    // 배열 초기화
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr[i][j] = INF;

    // i==j=0
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if (i==j)
                arr[i][j] = 0;

    // 길 입력
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
            scanf("%d", &arr2[i][j]);
            if (arr2[i][j] == 1)
                arr[i][j] = 1;
        }

    //플로이드 워셜 알고리즘
    for(k=0;k<n;k++) {
        if (i==k)
            continue;
        for(i=0;i<n;i++) {
            if (j==i || j==k)
                continue;
            for (j=0;j<n;j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    //출력
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++,d=0) {
            if (i==j) {
                for(k=0;k<n;k++) {
                    if (arr2[i][k] == 1 && arr[k][i] != INF)
                        d = 1;
                }
                if (d==1)
                    printf("1 ");
                else
                    printf("0 ");

            }
            else if (arr[i][j] == INF)
                printf("0 ");
            else
                printf("1 ");
        }
        printf("\n");
    }

    return 0;
}
