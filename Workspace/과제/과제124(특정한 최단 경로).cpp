#include <stdio.h>      //fin
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 999999999;
int n,m;

vector< pair<int,int> > road[801];

void dijkstra(int dist[], int t)
{
    int i,j;
    priority_queue< pair<int,int> > pq;

    //거리배열 초기화
    for(i=1;i<=n;i++)
        dist[i] = INF;

    //기본값 입력
    pq.push({0,t});
    dist[t] = 0;

    //다익스트라
    while (!pq.empty()) {
        int dis = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < dis)
            continue;


        for(i=0;i<road[cur].size();i++) {
            int k = dis + road[cur][i].second;

            if (k < dist[road[cur][i].first]) {
                dist[road[cur][i].first] = k;
                pq.push({-k, road[cur][i].first});
            }
        }
    }

    return;
}


int main()
{
    int i,j;
    int n1,n2,dis;
    int v1,v2;

    scanf("%d %d", &n, &m);

    int dist1[n+1];
    int dist2[n+1];
    int dist3[n+1];

    //길 입력받기
    for(i=1;i<=m;i++) {
        scanf("%d %d %d", &n1, &n2, &dis);

        road[n1].push_back({n2,dis});
        road[n2].push_back({n1,dis});
    }


    //다익스트라
    scanf("%d %d", &v1, &v2);

    dijkstra(dist1,1);
    dijkstra(dist2,v1);
    dijkstra(dist3,v2);


    //답 출력
    int sum1 = 0;
    int sum2 = 0;

    ///예외 처리
    if (dist1[v1] == INF || dist2[v2] == INF || dist3[n] == INF)
        sum1 = -1;
    else {
        sum1 = dist1[v1] + dist2[v2] + dist3[n];
        sum2 = dist1[v2] + dist3[v1] + dist2[n];
    }

    if (sum1 < sum2)
        printf("%d", sum1);
    else
        printf("%d", sum2);


    return 0;
}
