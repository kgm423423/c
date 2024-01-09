#include <stdio.h>      //fin
#include <vector>

using namespace std;

int main()
{
    int i,j,k;
    int sum = 0;
    int n;
    scanf("%d", &n);

    vector<int> v[n];

    //삼각형 입력받기
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++) {
            scanf("%d", &k);
            v[i].push_back(k);
        }

    //최고합 구하기
    for(i=n-1;i>=1;i--)
        for(j=0;j<i;j++)
            v[i][j] > v[i][j+1] ? v[i-1][j] += v[i][j] : v[i-1][j] += v[i][j+1];

    //출력
    printf("%d", v[0][0]);

    return 0;
}
