#include <stdio.h>      //fin
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> road[501];
int enter[501];
int arrTime[501];
int sortArr[501];
queue<int> q;

int n,m;

void topologySort()
{
    int i,j=1;

    //간선이 0 node q push
    for(i=1;i<=n;i++) {
        if (enter[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int x = q.front();

        sortArr[j] = x;
        q.pop();
        j++;

        for(i=0;i<road[x].size();i++) {
            enter[road[x][i]]--;

            if (enter[road[x][i]] == 0) {
                q.push(road[x][i]);
            }
        }
    }

    return;
}

void f(int i)
{
    int j;
    int n3 = 0;
        for(j=0;j<road[i].size();j++) {
            if (arrTime[road[i][j]] > n3)
                n3 = arrTime[road[i][j]];
        }
        arrTime[i]+=n3;

    return;
}

int main()
{
    int i,j;
    int n1,n2;

    scanf("%d", &n);

    //벡터 입력받기
    for(i=1;i<=n;i++) {
        scanf("%d", &n1);

        arrTime[i] = n1;

        scanf("%d", &n2);

        while(n2!=-1)
        {
            road[i].push_back(n2);
            enter[n2]++;
            scanf("%d", &n2);
        }
    }

    //위상정렬
    topologySort();

    //출력계산
    for(i=1;i<=n;i++) {
        f(i);
    }

    //출력
    for(i=1;i<=n;i++) {
        printf("%d\n", arrTime[i]);
    }

    return 0;
}
