#include <stdio.h>      //fin
#include <queue>

using namespace std;

int f()
{
    int i,j;
    int n,m;
    int priority[10] = {};
    int pIndex;
    int sum = 1;

    queue<pair<int,int>> q;

    scanf("%d %d", &n, &m);

    //배열 입력받기
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        q.push({i,x});
        priority[x]++;
    }

    //계수정렬 인덱스
    pIndex = 9;
    while(priority[pIndex] == 0)
        pIndex--;


    //계산
    while(true) {
        while(priority[pIndex] == 0)
            pIndex--;

        while(q.front().second < pIndex) {
            q.push({q.front().first, q.front().second});
            q.pop();
        }
        if (q.front().first == m)
            return sum;

        priority[pIndex]--;
        q.pop();
        sum++;
    }
}


int main()
{
    int i;
    int n;

    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("%d\n", f());
    }

    return 0;
}
