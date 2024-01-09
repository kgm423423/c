#include <stdio.h>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

const int n = 4;
int m = 0;

struct pos
{
    int y;
    int x;

};

bool road[n][n];
vector<struct pos> nodes[(n/2)+1],a;
int nodeNum[(n/2)+1];


int f(struct pos p)
{
    if (p.x < 0 || p.y < 0)
        return 0;
    if (p.x >= n || p.y >= n)
        return 0;
    if (!road[p.y][p.x])
        return 0;

    road[p.y][p.x] = false;

    nodes[m].push_back(p);

    struct pos p1 = {p.y-1, p.x};
    struct pos p2 = {p.y, p.x-1};
    struct pos p3 = {p.y, p.x+1};
    struct pos p4 = {p.y+1, p.x};

    return f(p1) + f(p2) + f(p3) + f(p4) + 1;
}


int main()
{
    srand(time(NULL));

    /// #1 배열 입력
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            road[i][j] = rand() % 2 == 1 ? true : false;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout << road[i][j];
        printf("\n");
    }
    printf("\n");

    /// #2 DFS
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if (road[i][j]) {
                struct pos p = {i,j};
                nodeNum[m] = f(p);
                m++;
            }

    for(int i=0;i<m;i++) {
        printf("%d | ", nodeNum[i]);

        for(int j=0;j<nodes[i].size();j++)
            printf("{%d,%d} ", nodes[i][j].y,nodes[i][j].x);
        printf("\n");
    }

    printf("\n-------------------------\n");

    /// #3 정렬
    for(int i=m-1;i>0;i--)
        for(int j=0;j<i;j++)
            if (nodeNum[j] < nodeNum[j+1]) {
                int k = nodeNum[j+1];
                nodeNum[j+1] = nodeNum[j];
                nodeNum[j] = k;

                a = nodes[j];
                nodes[j] = nodes[j+1];
                nodes[j+1] = a;
            }

    /// #4 답 노드 찍기
    for(int i=0;i<m;i++) {
        if (nodeNum[0] > nodeNum[i])
            break;
        else {
            for(int j=0;j<nodes[i].size();j++)
            road[nodes[i][j].y][nodes[i][j].x] = true;
        }
    }

    /// #5 답 출력
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout << road[i][j];
        printf("\n");
    }
    printf("end");

    return 0;
}
