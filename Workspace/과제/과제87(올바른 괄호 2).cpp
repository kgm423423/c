#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main()
{
    int d=1;
    char k='\0';

    int i=1;

    while (k!='\n') {
        scanf("%c", &k);
        if (k=='\n')
            break;

        if (k=='(')
            s.push(0);
        else if (k==')' && s.empty()) {
            d=0;
            break;
        }
        else
            s.pop();
        i++;
    }

    if (!s.empty())
        d=0;

    if (d==1)
        printf("good");
    else
        printf("bad");

    return 0;
}
