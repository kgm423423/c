#include <stdio.h>      //마지막에 0 출력됨
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr[9];
queue<int> q;
bool check[9]={};

void bfs(int n)
{
    int i;

    if (check[n]==false)
        q.push(n);

    check[n]=true;

    if (q.empty())
        return;

    printf("%d ", q.front());
    q.pop();

    for(i=0;i<arr[n].size();i++) {
        if (check[arr[n][i]]==false) {
            q.push(arr[n][i]);
            check[arr[n][i]]=true;
        }
    }

    bfs(q.front());
}

int main()
{
    arr[1].push_back(2);
    arr[1].push_back(3);
    arr[1].push_back(8);

    arr[2].push_back(1);
    arr[2].push_back(7);

    arr[3].push_back(1);
    arr[3].push_back(4);
    arr[3].push_back(5);

    arr[4].push_back(3);
    arr[4].push_back(5);

    arr[5].push_back(3);
    arr[5].push_back(4);

    arr[6].push_back(7);

    arr[7].push_back(2);
    arr[7].push_back(6);
    arr[7].push_back(8);

    arr[8].push_back(1);
    arr[8].push_back(7);

    bfs(1);

    return 0;
}
