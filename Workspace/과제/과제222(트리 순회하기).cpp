#include <stdio.h>
#include <queue>

using namespace std;

int n;
char arr[626] = {};

void makeTree()
{
    queue<int> q;

    q.push(1);

    while (!q.empty()) {
        int index = q.front();
        char c1,c2,c3;

        scanf(" %c %c %c", &c1, &c2, &c3);

        arr[index] = c1;

        printf("%d %d %d\n",index, index*2, (index*2)+1);

        if (c2 != '.')
            q.push(index*2);
        if (c3 != '.')
            q.push((index*2)+1);

        q.pop();
    }

    return;
}

void f(int i)
{
    if (i>=25 || arr[i] == 0 || arr[i] == '.')
        return;

    f(i*2);

    printf("%c\n", arr[i]);

    f((i*2)+1);

    return;
}

int main()
{
    int i;

    scanf("%d", &n);

    makeTree();

    for(i=1;i<=n;i++)
        printf("%c ", arr[i]);
    printf("\n\n");

    f(1);

    return 0;
}
