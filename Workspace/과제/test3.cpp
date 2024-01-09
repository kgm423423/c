#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int INF = 999999999;
int n,m;

vector<pair <int,int> > road[1001];

void dijkstra(int dist[], int s)
{
    int i;

    priority_queue <pair <int,int> > pq;

    for(i=1;i<=n;i++)
        dist[i] = INF;
    dist[s] = 0;
    pq.push({0,s});

    while (!pq.empty()) {
        int dis = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dis < dist[curr])
            continue;

        for(i=0;i<road[curr].size();i++) {
            int k = dis + road[curr][i].second;

            if (k < dist[road[curr][i].first]) {
                dist[road[curr][i].first] = k;
                pq.push({-k, road[curr][i].first});
            }
        }
    }

    return;
}


int main()
{
    int i,j;
    int s;
    scanf("%d %d", &n, &m);
    int dist[n+1];

    for(i=0;i<m;i++) {
        int n1,n2,dis;

        scanf("%d %d %d", &n1, &n2, &dis);

        road[n1].push_back({n2,dis});
    }

    scanf("%d", &s);

    dijkstra(dist, s);

    for(i=1;i<=n;i++)
        printf("%d ", dist[i]);

    return 0;
}
