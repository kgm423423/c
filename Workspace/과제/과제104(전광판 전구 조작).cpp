#include <stdio.h>      //fin
#include <iostream>
#include <queue>

using namespace std;

int m,n;
bool OF=false;

queue<pair<int,int>> q;

int BFS(bool arr[100][100])
{

    int i,j;
    int sum=0;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if (arr[i][j]==OF) {
                sum++;
                q.push({i,j});
                arr[i][j]=!OF;

                while (!q.empty()) {
                    int ii = q.front().first;
                    int jj = q.front().second;

                    if (ii>0 && arr[ii-1][jj]==OF) {
                        arr[ii-1][jj]=!OF;
                        q.push({ii-1,jj});
                    }
                    if (jj>0 && arr[ii][jj-1]==OF) {
                        arr[ii][jj-1]=!OF;
                        q.push({ii,jj-1});
                    }
                    if (jj<n-1 && arr[ii][jj+1]==OF) {
                        arr[ii][jj+1]=!OF;
                        q.push({ii,jj+1});
                    }
                    if (ii<m-1 && arr[ii+1][jj]==OF) {
                        arr[ii+1][jj]=!OF;
                        q.push({ii+1,jj});
                    }

                    q.pop();
                }
            }

    return sum;
}

int main()
{
    int i,j;
    scanf("%d %d",&m, &n);
    bool arr1[100][100];
    bool arr2[100][100];

    for(i=0;i<m;i++)
        for(j=0;j<n;j++) {
            cin >> arr1[i][j];
            arr2[i][j]=arr1[i][j];
        }

    printf("%d ",BFS(arr1));
    OF=true;
    printf("%d",BFS(arr2));

    return 0;
}
