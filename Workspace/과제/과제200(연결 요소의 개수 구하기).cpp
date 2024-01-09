#include <stdio.h>      //fin
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int i,j;
    int n,m;
    int sum = 0;
    scanf("%d %d", &n, &m);

    vector< int > road[n+1];
    bool check[n+1];
    stack< int > s;


    //체크 배열 초기화
    for(i=1;i<=n;i++)
        check[i] = true;


    //벡터 입력받기
    for(i=1;i<=m;i++) {
        int n1,n2;
        scanf("%d %d", &n1, &n2);

        road[n1].push_back(n2);
        road[n2].push_back(n1);
    }


    //노드 전부 확인
    for(i=1;i<=n;i++) {
        if (check[i]) {
            s.push(i);
            check[i] = false;

            ///BFS
            while(!s.empty()) {
                int x = s.top();

                s.pop();

                for(j=road[x].size()-1;j>=0;j--) {
                    if (check[road[x][j]]) {
                        s.push(road[x][j]);
                        check[road[x][j]] = false;
                    }
                }
            }
            sum++;
        }
    }

    printf("%d", sum);

    return 0;
}
