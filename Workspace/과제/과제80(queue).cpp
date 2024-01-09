#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main()
{
    int n;

    while(n!=-1) {
        scanf("%d", &n);

        if (n==0)
            q.pop();
        else if (n>0)
            q.push(n);
    }

    while(!q.empty())
    {
        printf("%d 3 7 ", q.front());
        q.pop();
    }

    return 0;
}

