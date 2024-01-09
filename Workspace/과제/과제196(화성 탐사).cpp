#include <stdio.h>
#include <queue>

using namespace std;

int dijkstra(int n)
{
    int i,j;

    int road[n][n];
    int sum[n][n];
    bool check[n][n];

    priority_queue < pair < int, pair <int,int> > > pq;


    //배열 입력
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &road[i][j]);



    //초기화
    sum[0][0] = road[0][0];
    pq.push({-road[0][0],{0,0}});

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            check[i][j] = true;


    //다익스트라
    while (!pq.empty()) {
        int dis = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;

        pq.pop();

        if (y>0 && check[y-1][x]) {
            sum[y-1][x] = road[y-1][x] + dis;
            check[y-1][x] = false;
            pq.push({-sum[y-1][x],{y-1,x}});
        }
        if (x>0 && check[y][x-1]) {
            sum[y][x-1] = road[y][x-1] + dis;
            check[y][x-1] = false;
            pq.push({-sum[y][x-1],{y,x-1}});
        }
        if (y<n-1 && check[y+1][x]) {
            sum[y+1][x] = road[y+1][x] + dis;
            check[y+1][x] = false;
            pq.push({-sum[y+1][x],{y+1,x}});
        }
        if (x<n-1 && check[y][x+1]) {
            sum[y][x+1] = road[y][x+1] + dis;
            check[y][x+1] = false;
            pq.push({-sum[y][x+1],{y,x+1}});
        }
    }


    return sum[n-1][n-1];
}

int main()
{
    int i;
    int m,k;

    scanf("%d", &m);

    for(i=0;i<m;i++) {
        scanf("%d", &k);
        printf("%d\n", dijkstra(k));
    }

    return 0;
}
