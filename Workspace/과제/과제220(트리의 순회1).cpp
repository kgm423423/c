#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector <pair <char, int> > t[26+1];

void f(int i)
{
    for(int j=0;j<t[i].size();j++) {
        printf("sum : %c %d %d\n", t[i][j].first, i, t[i].size());
        f(t[i][j].second);
    }

    return;
}

int main()
{
    int i,j,k;
    int c;
    int n;
    queue<int> q;

    scanf("%d", &n);

    i = 2; j=1; k = 0; c = 98;
    t[0].push_back({97, 1});
    while (n >= pow(2,k)) {
        printf("test1 %f\n", pow(2,k));
        while (!q.empty() && i <= n) {
            printf("test2 %d %d\n", i, q.front());
            t[q.front()].push_back({c, i});
            c++; i++;
            if (i <= n) {
                printf("test2 %d %d\n", i, q.front());
                t[q.front()].push_back({c, i});
                c++; i++;
            }
            q.pop();
        }

        while (j < pow(2,k+1)) {
            printf("test3 %d\n", j);
            q.push(j);
            j++;
        }

        k++;
    }

    printf("\n\n");
    f(0);

    return 0;
}
