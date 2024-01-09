#include <stdio.h>      //fin
#include <vector>

using namespace std;

vector<int> road[2000];
bool check[2000];

bool sum = false;
int n,m;

void f(int index, int cnt)
{
    if (cnt >= 5) {
        sum = true;
        return;
    }

    //printf("    %d %d\n", index, cnt);

    int i;
    for(i=0;i<road[index].size();i++) {
        //printf("        간선 갯수 %d\n", road[index].size());
        if (check[road[index][i]]) {
            check[road[index][i]] = false;
            f(road[index][i], cnt+1);
            check[road[index][i]] = true;
        }
    }

    return;
}

int main()
{
    int i,j;
    scanf("%d %d", &n, &m);

    //체크 초기화
    for(i=0;i<n;i++)
        check[i] = true;

    //백터 입력
    for(i=0;i<m;i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        road[n1].push_back(n2);
        road[n2].push_back(n1);
    }

    //DFS 완전탐색 가능확인
    for(i=0;i<n;i++) {
        //printf("\n시작노드 %d \n", i);
        check[i] = false;
        f(i, 1);
        check[i] = true;

        if (sum)
            break;
    }


    //답 출력
    if (sum)
        printf("1");
    else
        printf("0");

    return 0;
}
