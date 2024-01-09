#include <stdio.h>      //fin
#include <iostream>
#include <vector>

using namespace std;

const int INF = 999999999;

int n,m,x;

vector<pair<int,int>> road[1001];

struct node
{
    bool check;
    int dis;
};

int f(int xx)
{
    int i,j;
    int k;

    struct node arrF[n+1] = {};

    for(i=1;i<=n;i++)
        arrF[i].dis = INF;

    arrF[xx].dis = 0;

    for(i=1;i<=n;i++) {
        arrF[xx].check = true;

        for(j=0;j<road[xx].size();j++)
            if (arrF[xx].dis + road[xx][j].second < arrF[road[xx][j].first].dis)
                arrF[road[xx][j].first].dis = arrF[xx].dis + road[xx][j].second;

        if (xx==x)
            return arrF[x].dis;

        for(j=1, k=INF;j<=n;j++)
            if (arrF[j].check == false && arrF[j].dis < k) {
                k = arrF[j].dis;
                xx = j;
            }
    }

    return arrF[x].dis;
}

int main()
{
    int i,j;
    int n1,n2,t;
    int sum = 0;
    int xx;
    scanf("%d %d %d", &n, &m, &x);
    struct node arr[n+1] = {};

    for(i=1;i<=m;i++) {
        scanf("%d %d %d", &n1, &n2, &t);

        road[n1].push_back({n2,t});
    }

    for(i=1;i<=n;i++)       //배열 초기화
        arr[i].dis = INF;

    arr[x].dis = 0;

    for(i=1,xx=x ; i<=n ; i++) {
        arr[xx].check = true;

        for(j=0;j<road[xx].size();j++)
            if (arr[xx].dis + road[xx][j].second < arr[road[xx][j].first].dis)
                arr[road[xx][j].first].dis = arr[xx].dis + road[xx][j].second;

        for(j=1, n1=INF;j<=n;j++)
            if (arr[j].check == false && arr[j].dis < n1) {
                n1 = arr[j].dis;
                xx = j;
            }
    }

    for(i=1;i<=n;i++) {
        if (arr[i].dis + f(i) > sum)
            sum = arr[i].dis + f(i);
    }

    printf("%d", sum);

    return 0;
}
