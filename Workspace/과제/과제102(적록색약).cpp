#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n;

struct pos
{
    int x;
    int y;
};

int bfs(char arr[n][n])
{
    int i,j;
    int sum=0;
    queue<struct pos> q;
    bool checked[n][n];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if (arr[i][j]!='\0') {
                sum++;

            }





}

int main()
{
    int i,j;
    scanf("%d", &n);
    char arr[n][n];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%c", &arr[i][j]);

    printf("%d ", bfs(arr));

    return 0;
}
