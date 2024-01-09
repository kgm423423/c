#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 999999999;
int v,e;

vector<pair<int,int>> arr[20001];

struct dis
{
    bool k;
    int d;
};

struct dis sum[20001] = {};

void f(int n)
{
    sum[n].k = true;

    int i;
    int index;
    int dis = INF;
    int n1,n2;

    for(i=0;i<arr[n].size();i++) {
         n1 = sum[arr[n][i].first].d;
         n2 = sum[n].d + arr[n][i].second;

        if (n1 > n2)
            sum[arr[n][i].first].d = n2;
    }

    for(i=1;i<=v;i++) {
        if (sum[i].k == false && sum[i].d < dis) {
            dis = sum[i].d;
            index = i;
        }
    }

    if (dis == INF)
        return;

    f(index);

    return;
}

int main()
{
    int i;
    int s;
    scanf("%d %d %d", &v, &e, &s);

    for(i=1;i<=v;i++)
        if (i!=s)
            sum[i].d = INF;

    for(i=1;i<=e;i++) {
        int u,v,w;

        scanf("%d %d %d", &u, &v, &w);

        arr[u].push_back({v,w});
    }

    f(s);

    for(i=1;i<=v;i++) {
        if (sum[i].d == INF)
            printf("INF\n");
        else
            printf("%d\n", sum[i].d);
    }

        return 0;
}
