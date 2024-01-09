#include <stdio.h>      //fin77
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int enter[32001];
vector<int> road[32001];

int n,m;

void TopologySort()
{
    queue<int> q;

    int i,j;

    for(i=1;i<=n;i++) {
        if (enter[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int x = q.front();
        printf("%d ", x);
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
    int i;
    int n1,n2;

    scanf("%d %d",  &n, &m);

    for(i=0;i<m;i++) {
        scanf("%d %d", &n1, &n2);
        road[n1].push_back(n2);
        enter[n2]++;
    }

    TopologySort();

    return 0;
}
