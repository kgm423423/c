#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    long long int n,m;
    int sum = 0;


    /// 1.배열 만들어 초기화
    scanf("%lld %lld", &n, &m);
    int num = (int)sqrt(m);
    bool check[num+1];

    //초기화
    for(int i=1;i<=num;i++)
        check[i] = false;
    check[1] = true;


    /// 2.거의 소수 찾기
    for(int i=2;i<=num;i++) {
        if (!check[i]){
            //재곱수들 찾기
            int k = 2;
            while (n <= pow(i,k) && m >= pow(i,k)) {
                sum++;
                k++;
            }

            //에리스토테네스 체
            int j = i+i;

            while (j <= num) {
                check[j] = true;
                j += i;
            }
        }
    }


    /// 3.답 출력
    printf("%d", sum);

    return 0;
}
