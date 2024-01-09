#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n,m=0;

void left(bool arr[])
{
    int j;

    for(j=0;j<n;j++)
        arr[j] = arr[j+1];

    arr[n]=0;
    return;
}

void right(bool arr[])
{
    int j = n;

    for(j=n;j>0;j--) {
        arr[j] = arr[j-1];
    }

    arr[0]=0;
    return;
}

int main()
{
    int i,j;
    int n1,n2;
    int sum=0;
    queue<char> q;

    scanf("%d", &n);

    bool arr[n];



    ///배열 입력받기
    for(i=0;i<n;i++) {
        cin >> arr[i];

        if (arr[i])
            m++;
    }



    ///계산
    n--;
    for(i=0;i<m;i++) {
        n1=0; n2=n;

        while(!arr[n1])
            n1++;
        while(!arr[n2])
            n2--;
        n2 = n-n2;

        if (n1 < n2) {
            sum += n1+1;
            for(j=0;j<=n1;j++) {
                left(arr);
                q.push('L');
            }
        }
        else {
            sum += n2+1;
           for(j=0;j<=n2;j++) {
                right(arr);
                q.push('R');
            }
        }
    }



    ///출력
    printf("%d\n", sum);

    while(!q.empty()) {
        printf("%c", q.front());
        q.pop();
    }

    return 0;
}
