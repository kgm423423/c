#include <stdio.h>      //fin

const int INF = 999999999;

void printArr(int arr[5][5])
{
    int i,j;
    int n = 5;

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if (arr[i][j] == INF)
                printf("INF ");
            else
                printf("%-4d", arr[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    return;
}

int main()
{
    int i,j,k;
    int n,m;
    int x,y;
    scanf("%d %d", &n, &m);
    int arr[n][n];

    //배열 초기화
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr[i][j] = INF;

    for (k=0;k<m;k++) {
        scanf("%d %d", &i, &j);
        arr[i-1][j-1] = 1;
        arr[j-1][i-1] = 1;
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if (i==j)
                arr[i][j] = 0;

    //플로이드 워셜 알고리즘
    for(k=0;k<n;k++) {
        if (i==k)
            continue;
        for(i=0;i<n;i++) {
            if (j==i || j==k)
                continue;
            for(j=0;j<n;j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                     arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    //목표 입출력
    scanf("%d %d", &x, &y);

    if (arr[0][y-1] == INF || arr[y-1][x-1] == INF)
        printf("-1");
    else
        printf("%d", arr[0][y-1] + arr[y-1][x-1]);

    return 0;
}
