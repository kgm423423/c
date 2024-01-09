#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main()
{
    int n;

    while (n!=-1)
    {
        scanf("%d", &n);

        if (n>0)
            s.push(n);
        else if(n==0)
            s.pop();
    }

    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}
