#include <stdio.h>      //fin
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> road[1001];
bool check[1001];

int findNode(int index)
{
    int k=9999;

    for(int j=0;j<road[index].size();j++)
        if (!check[road[index][j]] && k > road[index][j])
            k = road[index][j];

    return k;
}

void DFS(bool check[], int index)
{
    printf("%d ", index);

    for(int i=0;i<road[index].size();i++) {
        int k = findNode(index);
        if (k == 9999)
            return;
        check[k] = true;
        DFS(check, k);
    }

    return;
}

void BFS(bool check[], int index)
{
    queue<int> q;
    q.push(index);
    check[index] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        printf("%d ", x);

        for(int i=0; i<road[x].size(); i++) {
            int k = findNode(x);
            if (k == 9999)
                break;
            check[k] = true;
            q.push(k);
        }
    }

    return;
}

int main()
{
    int i;
    int m;
    int index;

    scanf("%d %d %d", &n, &m, &index);

    //벡터 입력
    for(i=0;i<m;i++) {
        int n1,n2;
        scanf("%d %d", &n1, &n2);

        road[n1].push_back(n2);
        road[n2].push_back(n1);
    }


    //확인 배열 생성
    for(i=1;i<=n;i++)
        check[i] = false;

    //DFS
    check[index] = true;
    DFS(check, index);

    for(i=1;i<=n;i++)
        check[i] = false;

    printf("\n");

    //BFS
    BFS(check, index);

    return 0;
}
