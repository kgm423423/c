#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 999999999;

struct node
{
    bool check;
    int dis;
};

vector<pair<int,int>> road[10000];

void f(struct node arr[])
{
    int i,j;
    int x,n1,n2;

    priority_queue<pair<int,int>> q;

    for(i=1;i<=6;i++) {
        arr[i].check = false;
        arr[i].dis = INF;
    }

                                    printf("test2\n");

    arr[1].dis = 0;

    q.push({0,1});

    while(!q.empty())
    {
        printf("test3\n");
        x = q.top().second;

        q.pop();

        if (arr[x].check == true)
            continue;

        printf("test4\n");

        arr[x].check = true;

        for(i=0;i<road[x].size();i++) {
            n1 = road[x][i].second + arr[x].dis;
            n2 = arr[road[x][i].first].dis;

                                                printf("test5 %d\n", i);

            if (n1 < n2) {
                arr[road[x][i].first].dis = n1;
                q.push({n1, road[x][i].first});
                                                printf("test6\n");
            }
        }
    }

                                                printf("test7\n");
    return;
}

int main()
{
    int i,j;
    struct node arr[7];

    for(i=1;i<=6;i++) {
        arr[i].check = false;
        arr[i].dis = INF;
    }

    arr[1].dis = 0;

    road[1].push_back({2,2});
    road[1].push_back({3,5});
    road[1].push_back({4,1});

    road[2].push_back({3,3});
    road[2].push_back({4,2});

    road[3].push_back({2,3});
    road[3].push_back({6,1});

    road[4].push_back({3,3});
    road[4].push_back({5,1});

    road[5].push_back({3,1});
    road[5].push_back({6,2});

                                printf("test1\n");

    f(arr);

    for(i=1;i<=6;i++)
        printf("%d ", arr[i].dis);
}
