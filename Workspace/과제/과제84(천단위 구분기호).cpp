#include <bits/stdc++.h>

using namespace std;

stack<char> q;
stack<char> s;

int main()
{
    int i;
    int n;
    char k;

    scanf("%d", &n);
    getchar();

    for(i=0;i<n;i++) {
        scanf("%c", &k);
        q.push(k);
    }

    if (n>3) {
        for(i=0;i<3;i++) {
            s.push(q.top());
            q.pop();
        }

        for(i=0;i<n+((n-1)/3)-3;i++) {
            if (i%4==0)
                s.push(',');
            else {
                s.push(q.top());
                q.pop();
            }
        }
    }
    else {
        for(i=0;i<n;i++) {
            s.push(q.top());
            q.pop();
        }
    }

    while(!s.empty()) {
        if (s.top()=='\0')
            printf("0");
        else
            printf("%c", s.top());
        s.pop();
    }

    return 0;
}
