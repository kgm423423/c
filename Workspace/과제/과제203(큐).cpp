#include <stdio.h>              //fin
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

void GetString(char str[])
{
    int i=0;
    char k = '\0';

    while(k!='\n' && k!=32) {
        scanf("%c", &k);

        str[i] = k;
        i++;
    }
        str[i-1] = '\0';

    return;
}

int main()
{
    queue<int> q;

    int i;
    int n;
    int x;
    char a[10];
    scanf("%d", &n);
    getchar();

    for(i=0;i<n;i++) {
        GetString(a);

        if (strcmp(a,"push") == 0) {
            scanf("%d", &x);
            getchar();
            q.push(x);
        }
        else if (strcmp(a,"pop") == 0) {
            if (q.empty())
                printf("-1\n");
            else {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (strcmp(a,"size") == 0) {
            printf("%d\n", q.size());
        }
        else if (strcmp(a,"empty") == 0) {
            cout << q.empty();
            printf("\n");
        }
        else if (strcmp(a,"front") == 0) {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.front());
        }
        else if (strcmp(a,"back") == 0) {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.back());
        }
    }

    return 0;
}
