#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> road[10001];
int enter[10001];
int time[10001];
int sortArr[10001];
queue<int> q;

int n;

void topologySort()
{
    int i,j;

    //간선이 0 node push
    for(i=1;i<=n;i++) {
        if (enter[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        j=1;
        int x = q.front();
        sortArr[j] = x;
        q.pop();

        for(i=0;i<road[x].size();i++) {
            enter[road[x][i]]--;
            if (enter[road[x][i]] == 0)
                q.push(road[x][i]);
        }
    }

    return;
}

int main()
{
    int i,j;
    int n1,n2;
    scanf("%d", &n);

    //벡터 입력
    for(i=1;i<=n;i++) {
        scanf("%d %d", &n1, &n2);

        time[i] = n1;
        for(j=1;j<=n2;j++) {
            scanf("%d", &n1);
            road[i].push_back(n1);
            enter[n1]++;
        }
    }

    //위상정렬
    topologySort();

    for(i=1;i<=n;i++) {
        printf("%d ", sortArr[i]);
    }

    return 0;
}
