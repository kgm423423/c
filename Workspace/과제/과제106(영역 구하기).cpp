#include <stdio.h>      //fin
#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> q;

int m,n;

void fill(bool arr[100][100], int x1, int y1, int x2, int y2)
{
    int i,j;

    for(i=y1;i<y2;i++)
        for(j=x1;j<x2;j++)
            arr[i][j]=true;

    return;
}

int BFS(bool arr[100][100], int i, int j)
{
    int sum=0;

    q.push({i,j});
    arr[i][j]=true;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        if (y > 0 && arr[y-1][x] == false) {
            q.push({y-1,x});
            arr[y-1][x]=true;
        }
        if (x > 0 && arr[y][x-1] == false) {
            q.push({y,x-1});
            arr[y][x-1]=true;
        }
        if (x < n-1 && arr[y][x+1] == false) {
            q.push({y,x+1});
            arr[y][x+1]=true;
        }
        if (y < m-1 && arr[y+1][x] == false) {
            q.push({y+1,x});
            arr[y+1][x]=true;
        }

        q.pop();
        sum++;
    }

    return sum;
}

int main()
{
    int i,j;
    int k;
    int sum=0;
    scanf("%d %d %d", &m, &n, &k);
    bool arr[100][100]={};
    int countSort[(m*n)+1];

    for(i=0;i<m*n;i++)
        countSort[i]=0;

    for(i=0;i<k;i++) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        fill(arr,x1,y1,x2,y2);
    }

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if (arr[i][j]==false) {
                sum++;
                countSort[BFS(arr,i,j)]++;
            }

    printf("%d\n", sum);

    for(i=1;i<(n*m);i++) {
        for(j=0;j<countSort[i];j++)
            printf("%d ", i);
    }

    return 0;
}
