#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

int main()
{
    string a;
    int i=0;
    char k;

    cin >> a;

    while(a[i]!='\0')
    {
        s.push(a[i]);
        i++;
    }

    while(!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }

    return 0;
}
