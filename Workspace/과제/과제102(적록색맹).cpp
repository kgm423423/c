#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

struct pos
{
    int y;
    int x;
};

queue<struct pos> q;

const int n=5;        //함수 상수 오류때문에 임시 설정

void BFS_RGB(char arr[][n])
{
    int i,j;
    int sum=0;
    bool checked[n][n]={};

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if (checked[i][j]==false) {
                sum++;
                q.push({i,j});
                checked[i][j]=true;

                while(!q.empty()) {
                    if (q.front().y-1>=0 && checked[q.front().y-1][q.front().x]==false && arr[q.front().y-1][q.front().x]==arr[q.front().y][q.front().x]) {
                        q.push({q.front().y-1, q.front().x});
                        checked[q.front().y-1][q.front().x]=true;
                    }
                    if (q.front().x-1>=0 && checked[q.front().y][q.front().x-1]==false && arr[q.front().y][q.front().x-1]==arr[q.front().y][q.front().x]) {
                        q.push({q.front().y, q.front().x-1});
                        checked[q.front().y][q.front().x-1]=true;
                    }
                    if (q.front().x<n && checked[q.front().y][q.front().x+1]==false && arr[q.front().y][q.front().x+1]==arr[q.front().y][q.front().x]) {
                        q.push({q.front().y, q.front().x+1});
                        checked[q.front().y][q.front().x+1]=true;
                    }
                    if (q.front().y<n && checked[q.front().y+1][q.front().x]==false && arr[q.front().y+1][q.front().x]==arr[q.front().y][q.front().x]) {
                        q.push({q.front().y+1, q.front().x});
                        checked[q.front().y+1][q.front().x]=true;
                    }
                    q.pop();
                }
            }
        }
    }

    printf("%d ", sum);

    return;
}

void BFS_GB(char arr[][n])
{
    int i,j;
    int sum=0;
    bool checked[n][n]={};

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if (arr[i][j]=='R')
                arr[i][j]='G';

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if (checked[i][j]==false) {
                sum++;
                q.push({i,j});
                checked[i][j]=true;

                while(!q.empty()) {
                    if (q.front().y-1>=0 && checked[q.front().y-1][q.front().x]==false && arr[q.front().y-1][q.front().x]==arr[q.front().y][q.front().x]) {
                        q.push({q.front().y-1, q.front().x});
                        checked[q.front().y-1][q.front().x]=true;
                    }
                    if (q.front().x-1>=0 && checked[q.front().y][q.front().x-1]==false && arr[q.front().y][q.front().x-1]==arr[q.front().y][q.front().x]) {
                        q.push({q.front().y, q.front().x-1});
                        checked[q.front().y][q.front().x-1]=true;
                    }
                    if (q.front().x<n && checked[q.front().y][q.front().x+1]==false && arr[q.front().y][q.front().x+1]==arr[q.front().y][q.front().x]) {
                        q.push({q.front().y, q.front().x+1});
                        checked[q.front().y][q.front().x+1]=true;
                    }
                    if (q.front().y<n && checked[q.front().y+1][q.front().x]==false && arr[q.front().y+1][q.front().x]==arr[q.front().y][q.front().x]) {
                        q.push({q.front().y+1, q.front().x});
                        checked[q.front().y+1][q.front().x]=true;
                    }
                    q.pop();
                }
            }
        }
    }

    printf("%d", sum);

    return;
}

int main()
{
    int i,j;
    //scanf("%d", &n);
    char arr[n][n];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf(" %c", &arr[i][j]);

    BFS_RGB(arr);
    BFS_GB(arr);

    return 0;
}
