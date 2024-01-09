#include <stdio.h>      //fin
#include <queue>

using namespace std;

int main()
{
    int i;
    int x;
    int n;

    queue<int> q;

    scanf("%d", &n);

    for(i=1;i<=n;i++)
        q.push(i);

    while(q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    printf("%d", q.front());

    return 0;
}
