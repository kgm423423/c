#include <bits/stdc++.h>

using namespace std;

stack<char> s;

int f()
{
    int n=s.top();
    if (n<58) {
        s.pop();
        return n-48;
    }
    else {
        s.pop();
        return n-55;
    }
}

int main()
{
    int i,n1,n2;
    char k;
    _Bool isOk=1;

    scanf("%c", &k);

    if (k=='O') {
        while (k!='\n') {
            scanf("%c", &k);
            s.push(k);
        }
        s.pop();
        if (!s.top()=='X')
            isOk=0;
        s.pop();
    }
    else
        isOk=0;

    if (isOk==1) {
        while (!s.empty()) {
            n1=f();
            n2=f();
            printf("%c", (char)(n1*16)+n2);
        }
    }
    else
        printf("data error");

    return 0;
}
