#include <stdio.h>
#include <vector>

using namespace std;

vector <int> tree[100000+1];
bool check[100000+1];
int sum[100000+1];

void f(int index)
{
    for(int i=0;i<tree[index].size();i++) {
        int num = tree[index][i];
        if (!check[num]) {
            sum[num] = index;
            check[num] = true;
            f(num);
        }
    }

    return;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=1;i<n;i++) {
        int n1,n2;
        scanf("%d %d", &n1, &n2);

        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    //for(int i=1;i<=n;i++)
      //  check[i] = false;

    f(1);

    for(int i=2;i<=n;i++)
        printf("%d\n", sum[i]);

    return 0;
}
