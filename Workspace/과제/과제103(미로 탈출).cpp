#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

const int n=5,m=6;      //여기도 오류남

struct pos
{
    int y;
    int x;
};

queue<struct pos> q;

void BFS(int arr[n][m])
{
    while (q.front().y+1!=n && q.front().x+1!=m) {
        if (q.front().y-1>=0 && arr[q.front().y-1][q.front().x]==1) {
            printf(" 1 ");
            q.push({q.front().y-1, q.front().x});
            arr[q.front().y-1][q.front().x]=arr[q.front().y][q.front().x]+1;
        }
        if (q.front().x-1>=0 && arr[q.front().y][q.front().x-1]==1) {
            printf(" 2 ");
            q.push({q.front().y, q.front().x-1});
            arr[q.front().y][q.front().x-1]=arr[q.front().y][q.front().x]+1;
        }
        if (q.front().x<m && arr[q.front().y][q.front().x+1]==1) {
            printf(" 3 ");
            q.push({q.front().y, q.front().x+1});
            arr[q.front().y][q.front().x+1]=arr[q.front().y][q.front().x]+1;
        }
        if (q.front().y<n && arr[q.front().y+1][q.front().x]==1) {
            printf(" 4 ");
            q.push({q.front().y+1, q.front().x});
            arr[q.front().y+1][q.front().x]=arr[q.front().y][q.front().x]+1;
        }
        q.pop();
    }

    printf("\n%d", arr[n][m]);

    return;
}

int main()
{
    int i,j;
    //scanf("%d %d", &n, &m);
    int arr[n][m];

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    q.push({0,0});

    printf("\n입력완료\n");
    BFS(arr);

    return 0;
}
