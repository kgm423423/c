#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int i;
int sum = 100000000;

int arr[4] = {1,5,6,9};

void f(int r,int n)
{
    if (n>=sum) {
        q.pop();
        return;
    }

    if (r==0 && n<sum) {
        sum=n;
        q.pop();
        return;
    }

    int j;

    for(j=3;j>=0;j--) {
        if (arr[j]<=r) {
            q.push(arr[j]);
            f(r-arr[j],n+1);
        }
    }

    q.pop();

    return;
}

int main()
{
    int r;

    scanf("%d", &r);

    i=1;
    f(r,0);

    while(!q.empty()) {
        printf("%d ", q.front());
        q.pop();
    }

    printf("\n%d", sum);

    return 0;
}
