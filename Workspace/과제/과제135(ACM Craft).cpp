#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologySort()
{
    int i,j;
    int n,m;
    int n1,n2;
    int t;
    int sum = 0;

    scanf("%d %d", &n, &m);

    vector<int> road[n];
    int enter[n] = {};
    int time[n];
    bool check[n] = {};
    queue<int> q;

    queue<int> sumArr;

    //소요시간 입력받기
    for(i=0;i<n;i++)
        scanf("%d", &time[i]);

    //vector 입력받기
    for(i=0;i<m;i++) {
        scanf("%d %d", &n1, &n2);

        road[n1-1].push_back(n2-1);
        enter[n2-1]++;
    }

    //진입차수 0노드 삽입
    for(i=0;i<n;i++)
    if (enter[i] == 0)
        q.push(i);

    printf("test1\n");

    //위상 정렬
    while (!q.empty()) {
        int x = q.front();

        sumArr.push(x);

        q.pop();

        for(i=0;i<road[x].size();i++) {
            enter[road[x][i]]--;

            if (enter[road[x][i]] == 0)
                q.push(road[x][i]);
        }
        printf("test2\n");
    }

    //타겟 입력
    scanf("%d", &t);


    /*
    while (!sumArr.empty()) {
        printf("SortTest%d\n", sumArr.front());
        sumArr.pop();
    }

    */


    //타겟까지 시간 계산
    sum += time[sumArr.front()];

    while(check[t-1] == false) {
        int x = sumArr.front();
        int p = 0;

        sumArr.pop();

        for(i=0;i<road[x].size();i++) {
            if (check[road[x][i]] == false && time[road[x][i]] > p)
                p = time[road[x][i]];

            check[road[x][i]] = true;
        }

        printf("test3 x:%d sum:%d\n", x+1 , sum);

        sum += p;
    }

    //출력
    printf("sum : %d\n", sum);

    return;
}

int main()
{
    int i;
    int n;
    scanf("%d", &n);

    for(i=0;i<n;i++)
        topologySort();

    return 0;

}
