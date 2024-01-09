#include <stdio.h>      //fin
#include <vector>

using namespace std;

int n,m;
int sum = 0;

vector<int> road[1001];


void BFS(bool check[], int index)
{
    int i;

    for(i=0;i<road[index].size();i++) {
        if (check[road[index][i]]) {
            check[road[index][i]] = false;
            BFS(check, road[index][i]);
        }
    }

    return;
}

int main()
{
    int i,j;
    scanf("%d %d", &n, &m);
    bool check[n+1];

    for(i=1;i<=n;i++)
        check[i] = true;

    //로드 입력
    for(i=1;i<=m;i++) {
        int n1,n2;
        scanf("%d %d", &n1, &n2);

        road[n1].push_back(n2);
        road[n2].push_back(n1);
    }


    //BFS
    for(i=1;i<=n;i++) {
        if (check[i]) {
            check[i] = false;
            BFS(check, i);
            sum++;
        }
    }

    printf("%d", sum);

    return 0;
}
