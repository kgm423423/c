#include <stdio.h>      //fin
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int i,ii,jj;
    int n,m;    //n 컴퓨터 수 m 연결
    int sum = 0;
    scanf("%d %d", &n, &m);
    vector<int> arr[n+1];
    queue<int> q;
    bool checked[n+1]={};
    for(i=0;i<m;i++) {
        scanf("%d %d", &ii, &jj);
        arr[ii].push_back(jj);
        arr[jj].push_back(ii);
    }

    q.push(1);
    checked[1] = true;

    while (!q.empty()) {
        for(int i=0;i<arr[q.front()].size();i++)
            if (checked[arr[q.front()][i]] == false) {
                sum++;
                q.push(arr[q.front()][i]);
                checked[arr[q.front()][i]] = true;
            }
        q.pop();
    }
    printf("%d",sum);

    return 0;
}
