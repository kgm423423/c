#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int inf = 99999999;

struct dis
{
    bool k;
    int d;
};

vector<pair<int,int>> arr[7];
struct dis sum[7]={};

void f(int n)
{
    sum[n].k=true;

    int i;
    int index;
    int dis = inf;
    int n1,n2;

    for(i=0;i<arr[n].size();i++) {
         n1 = sum[arr[n][i].first].d;
         n2 = sum[n].d + arr[n][i].second;

        if (n1 > n2)
            sum[arr[n][i].first].d = n2;
    }

    for(i=1;i<7;i++)
        printf("%d ", sum[i].d);

    printf("\n\n");


    for(i=1;i<7;i++) {
        if (sum[i].k == false && sum[i].d < dis) {
            dis = sum[i].d;
            index = i;
        }
    }

    if (dis == inf)
        return;

    f(index);

    return;
}

int main()
{
    arr[1].push_back({4,4});
    arr[1].push_back({5,3});
    arr[1].push_back({6,2});

    arr[2].push_back({3,1});

    arr[3].push_back({4,2});

    arr[4].push_back({5,1});

    arr[5].push_back({6,2});

    arr[6].push_back({3,1});

    int i;

    for(i=2;i<7;i++)
        sum[i].d=inf;

    f(1);

    for(i=1;i<7;i++)
        printf("%d ", sum[i].d);

    return 0;
}
