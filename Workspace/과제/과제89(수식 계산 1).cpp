#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main()
{
    int i=0;
    char k='\0';

    while(k!='\n') {
        scanf("%c", &k);

        if (k>=48 && k<=57)
            s.push(k-48);
        else if (k=='+') {
            i=s.top();
            s.pop();
            i+=s.top();
            s.pop();
            s.push(i);
        }
        else if (k=='-') {
            i=s.top();
            s.pop();
            i=s.top()-i;
            s.pop();
            s.push(i);
        }
        else if (k=='*') {
            i=s.top();
            s.pop();
            i*=s.top();
            s.pop();
            s.push(i);
        }
        else if (k=='/') {
            i=s.top();
            s.pop();
            i/=s.top();
            s.pop();
            s.push(i);
        }
    }
    printf("%d", i);

    return 0;
}
