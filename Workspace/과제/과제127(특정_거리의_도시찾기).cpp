#include <stdio.h>      //fin
#include <iostream>
#include <vector>
#include <queue>

using namespace std;    //7:45 시작

int main()
{
    //입력받기
    int i,j;
    int n,m;
    int k,x;
    scanf("%d %d %d %d",&n, &m, &k, &x);
    vector<int> arr[n];
    queue<int> q;
    int checked[n] = {};
    int sum[n] = {};

    for(i=0;i<m;i++) {
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        arr[n1-1].push_back(n2-1);
    }
    x--; //인덱스는 -1

    //BFS
    q.push(x);
    checked[x] = 1;

    while(!q.empty()) {
        int t = q.front();
        q.pop();

        for(i=0;i<arr[t].size();i++) {
            int tt = arr[t][i];

            if (checked[tt]==0) {
                q.push(tt);
                checked[tt] = 1;
                sum[tt] = sum[t]+1;
            }
        }
    }

    //특정거리출력

    bool B = false;

    for(i=0;i<n;i++) {
        if (sum[i] == k) {
            printf("%d ",i+1);
            B = true;
        }
    }

    if (B==false)
        printf("-1");

    return 0;
}
