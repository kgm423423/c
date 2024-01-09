#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 999999999;

vector<pair<int,int>> road[7];

struct node
{
    bool check;
    int dis;
};

int main()
{
    int i,j,ii;
    struct node arr[7] = {};
    int x = 1;
    int n;
    int k;

    road[1].push_back({2,2});
    road[1].push_back({3,5});
    road[1].push_back({4,1});

    road[2].push_back({3,3});
    road[2].push_back({4,2});

    road[3].push_back({2,3});
    road[3].push_back({6,5});

    road[4].push_back({5,1});

    road[5].push_back({3,1});
    road[5].push_back({6,2});

    for(i=2;i<=6;i++)
        arr[i].dis = INF;

    for(i=1;i<=6;i++) {

        arr[x].check = true;

        for(j=0;j<road[x].size();j++) {        // 계산
            if (arr[x].dis + road[x][j].second < arr[road[x][j].first].dis)
                arr[road[x][j].first].dis = arr[x].dis + road[x][j].second;
        }

        for(ii=1, n=INF;ii<=6;ii++)         //전환
            if (arr[ii].check == false && arr[ii].dis < n) {
                n = arr[ii].dis;
                x = ii;
            }
    }

    for(i=1;i<=6;i++)
        printf("%d ", arr[i].dis);
    printf("\n");

    return 0;
}
