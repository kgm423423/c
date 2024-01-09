#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector <int> tree[50];
bool del[50];

void f(int index)
{
    int vecSize = tree[index].size();
    for(int i=0;i<vecSize;i++) {
        f(tree[index][0]);
        del[tree[index][0]] = true;
        tree[index].erase(tree[index].begin() + 0);
    }

    return;
}

void VecDel(int target)
{
    queue<int> q;

    q.push(0);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i=0;i<tree[x].size();i++) {
            int num = tree[x][i];

            if (num==target) {
                tree[x].erase(tree[x].begin() + i);
                return;
            }


            q.push(num);
        }
    }

    return;
}

int main()
{
    int n,m;
    int sum = 0;
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        int num;
        scanf("%d", &num);

        if (num == -1)
            continue;

        tree[num].push_back(i);
    }

    scanf("%d", &m);

    f(m);
    del[m] = true;
    VecDel(m);

    for(int i=0;i<n;i++) {
        if (del[i] == false && tree[i].empty()) {
            sum++;
        }
    }

    printf("%d", sum);

    return 0;
}
