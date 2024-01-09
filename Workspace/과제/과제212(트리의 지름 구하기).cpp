#include <stdio.h>
#include <vector>
#include <queue>
#define INF 999999999

using namespace std;


int n;

vector <pair <int,int> > tree[100001];


void Dijkstra(int dist[], int start)
{
    priority_queue <pair <int,int> > pq;

    for(int i=1; i <= n ; i++)
        dist[i] = INF;

    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        int x = pq.top().first;
        int d = -pq.top().second;
        pq.pop();

        if (dist[x] < d)
            continue;

        for(int i=0;i < tree[x].size();i++) {
            int cost = tree[x][i].second + d;

            if (cost < dist[tree[x][i].first]) {
                dist[tree[x][i].first] = cost;
                pq.push({tree[x][i].first, -cost});
            }
        }
    }

    return;
}

int main()
{
    int i;
    int sum = 0;

    scanf("%d", &n);



    /// #1 트리 입력받기
    for(i=0;i<n;i++) {
        int n1;
        int n2 = 0;
        int dist;

        scanf("%d", &n1);

        while(n2 != -1) {
            scanf("%d", &n2);

            if (n2 == -1)
                break;
            else {
                scanf("%d", &dist);

                tree[n1].push_back({n2, dist});
                tree[n2].push_back({n1, dist});
            }
        }
    }



    /// #2 지름 구하기
    for(i=1;i<=n;i++) {
        int dist[n+1];

        //다익스트라
        Dijkstra(dist, i);

        for(int j=1;j<=n;j++)
            if (dist[j] > sum)
                sum = dist[j];
    }



    /// #3 답 출력
    printf("%d", sum);

    return 0;
}
