#include <stdio.h>

using namespace std;

int main()
{
    int i,j;
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[n+1][n+1];


    //0번 초기화
    for(i=0;i<=n;i++)
        arr[0][i] = 0;
    for(i=1;i<=n;i++)
        arr[i][0] = 0;


    //합 입력받기
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) {
            scanf("%d", &arr[i][j]);
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }


    //합 출력하기
    for(i=0;i<m;i++) {
        int n1x,n1y;
        int n2x,n2y;
        scanf("%d %d %d %d", &n1x, &n1y, &n2x, &n2y);
        printf("%d", arr[n2y][n2x] - arr[n1y-1][n2x] - arr[n2y][n1x-1] + arr[n1y-1][n1x-1]);
    }

    return 0;
}
