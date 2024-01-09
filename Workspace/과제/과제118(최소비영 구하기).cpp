#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int inf = 99999999;
int v,m;

struct node
{
    bool k;
    int d;
};

struct node sum[1001] = {};;

vector<pair<int,int>> arr[100001];

void f(int n)
{
    int i;
    int index;
    int dis = inf;
    int n1,n2;

    for(i=0;i<arr[n].size();i++) {
        printf("test1");
        n1 = sum[arr[n][i].first].d;
        n2 = sum[n].d + arr[n][i].second;

        if (n1 > n2)
            sum[arr[n][i].first].d = n2;
    }

    for(i=1;i<=v;i++)
        if (sum[i].k == false && sum[i].d < dis) {
            printf("test2");
            dis = sum[i].d;
            index = i;
        }

    if (dis == inf)
        return;



    f(index);

    printf("Å×½ºÆ®");

    return;
}


int main()
{
    int i;

    scanf("%d %d", &v, &m);

    for(i=2;i<=v;i++)
        sum[i].d = inf;

    for(i=1;i<=m;i++) {
        int n1,n2,n3;

        scanf("%d %d %d", &n1, &n2, &n3);

        arr[n1].push_back({n2,n3});
    }

    f(1);

    printf("%d", sum[v].d);

    return 0;
}
