#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int ii,jj;
    int i,j;
    int n,m;
    int sy,sx;
    int sSize=2,fish=0;
    int sum=0;
    scanf("%d",&n);
    int arr[n][n];

    //배열 입력받기
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
           scanf("%d",&arr[i][j]);
           if (arr[i][j] > 0) {
                if (arr[i][j] == 9) {
                    sy = i; sx = j;
                }
                else
                    m++;
           }
        }

    //물고기 개수만큼 반복
    for(i=0;i<m;i++) {
        queue< pair<int,int> > q;
        int arr2[n][n];
        bool checked[n][n];
        q.push({sy,sx});
        checked[sy][sx] = true;

        for(int ii=0;ii<n;ii++) for(int jj=0;jj<n;jj++) arr2[ii][jj] = 0;
        for(int ii=0;ii<n;ii++) for(int jj=0;jj<n;jj++) checked[ii][jj] = false;

        //BFS
        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;

            if (arr[y][x] != 0 && arr[y][x] < sSize) {
                sum += arr2[y][x];
                arr[sy][sx] = 0;
                sy = y; sx = x;
                arr[y][x] = 9;
                fish++;
                break;
            }

            q.pop();

            if (y>0 && checked[y-1][x] == false && sSize >= arr[y-1][x]) {
                q.push({y-1,x});
                checked[y-1][x] = true;
                arr2[y-1][x] = arr2[y][x] + 1;
            }
            if (x>0 && checked[y][x-1] == false && sSize >= arr[y][x-1]) {
                q.push({y,x-1});
                checked[y][x-1] = true;
                arr2[y][x-1]  = arr2[y][x] + 1;
            }
            if (x<n-1 && checked[y][x+1] == false && sSize >= arr[y][x+1]) {
                 q.push({y,x+1});
                 checked[y][x+1] = true;
                 arr2[y][x+1]  = arr2[y][x] + 1;
            }
            if (y<n-1 && checked[y+1][x] == false && sSize >= arr[y+1][x]) {
                 q.push({y+1,x});
                 checked[y+1][x] = true;
                 arr2[y+1][x]  = arr2[y][x] + 1;
            }
        }
        if (q.empty())
            break;

        if (fish == sSize) {
            sSize++;
            fish=0;
        }

        printf("\n\n");
        for(ii=0;ii<n;ii++) {
            for(jj=0;jj<n;jj++)
                printf("%d ",arr[ii][jj]);
            printf("\n");
        }
    }

    printf("%d", sum);

    return 0;
}
