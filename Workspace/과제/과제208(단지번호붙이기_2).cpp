#include <stdio.h>      //fin
#include <iostream>
#include <queue>

using namespace std;

int n;
bool arr[25][25];

int DFS(int i, int j)
{
    if (i<0 || i>=n || j<0 || j>=n || !arr[i][j])
        return 0;
    else
        arr[i][j] = false;

    return DFS(i+1,j) + DFS(i, j-1) + DFS(i, j+1) + DFS(i-1, j) + 1;
}

int main()
{
    int i,j;

    scanf("%d", &n);
    getchar();

    priority_queue<int> pq;

    //배열 입력받기
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            char k;

            scanf("%c", &k);

            if (k=='1')
                arr[i][j] = true;
            else
                arr[i][j] = false;
        }
        getchar();
    }

    //DFS
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if (arr[i][j])
                pq.push(-DFS(i, j));

    //정답 출력
    printf("%d\n", pq.size());

    while(!pq.empty()) {
        printf("%d\n", -pq.top());
        pq.pop();
    }

    return 0;
}
