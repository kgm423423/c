#include <stdio.h>  //미완(왜인지 모르겠음)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int i,j;
    int n,m;
    int n1,n2;
    scanf("%d %d", &n, &m);

    vector<int> road[n];
    int enter[n] = {};
    bool check[n] = {};
    queue<int> q;

    for(i=0;i<m;i++) {
        scanf("%d %d", &n1, &n2);

        road[n1-1].push_back(n2-1);
        enter[n2-1]++;
    }

    for(i=0;i<n;i++) {
        if (q.empty() == true) {
            for(j=0;j<n;j++) {
                if (enter[j] == 0 && check[j] == false) {
                    q.push(j);
                    check[j] = true;
                    break;
                }
            }
        }
        int x = q.front();
        printf("%d ", x+1);

        q.pop();

        for(j=0;j<road[x].size();j++) {
            enter[road[x][j]]--;

            if (enter[road[x][j]] == 0 && check[road[x][j]] == false) {
                q.push(road[x][j]);
                check[road[x][j]] = true;
            }

        }
    }

    return 0;
}
