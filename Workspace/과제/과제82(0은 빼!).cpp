#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main()
{
    int i,j;;
    int n,k;
    int sum=0;

    scanf("%d", &n);

    for(i=0;i<n;i++) {
        scanf("%d", &k);

        if (k==0)
            s.pop();
        else
            s.push(k);
    }

    while(!s.empty()) {
        sum+=s.top();
        s.pop();
    }

    printf("%d", sum);

    return 0;
}
