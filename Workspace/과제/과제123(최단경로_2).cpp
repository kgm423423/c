#include <stdio.h>      //fin
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 999999999;

struct node
{
    bool check;
    int dis;
};

int main()
{
    int i;
    int n,m,x;
    int n1,n2,n3;
    scanf("%d %d", &n, &m);
    struct node arr[n+1];
    vector< pair< int,int > > road[n+1];
    priority_queue < pair <int,int> > q;
    scanf("%d", &x);

    //배열 초기화
    for(i=1;i<=n;i++) {
        arr[i].check = false;
        arr[i].dis = INF;
    }
    arr[x].dis = 0;
    q.push({0,x});

    //로드 입력
    for(i=1;i<=m;i++) {
        scanf("%d %d %d", &n1, &n2, &n3);
        road[n1].push_back({n2,n3});
    }

    //다익스트라
    while(!q.empty()) {
        x = q.top().second;
        q.pop();

        //체크
        if (arr[x].check == true)
            continue;
        arr[x].check = true;

        //연산
        for(i=0;i<road[x].size();i++) {
            n1 = arr[x].dis + road[x][i].second;
            n2 = arr[road[x][i].first].dis;

            if (n1 < n2) {
                arr[road[x][i].first].dis = n1;
                q.push({-n1,road[x][i].first});
            }
        }
    }

    //출력
    for(i=1;i<=n;i++) {
        if (arr[i].dis == INF)
            printf("INF\n");
        else
            printf("%d\n", arr[i].dis);
    }
}
