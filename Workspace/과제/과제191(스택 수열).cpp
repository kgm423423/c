#include <stdio.h>      //fin
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int i,j;
    int n;
    bool check = true;

    stack<int> s;
    queue<int> q;
    queue<char> sum;

    scanf("%d", &n);

    for(i=0;i<n;i++) {
        int m;
        scanf("%d", &m);
        q.push(m);
    }

    i=1;
    while (!q.empty()) {
            while (q.front() >= i) {
                sum.push('+');
                s.push(i);
                i++;
            }
            if (q.front() == s.top()) {
                sum.push('-');
                s.pop();
            }
            else {
                check = false;
                break;
            }

        q.pop();
    }

    if (check)
        while (!sum.empty()) {
            printf("%c\n", sum.front());
            sum.pop();
        }
    else
        printf("NO");


    return 0;
}
