#include <stdio.h>
#include <iostream>

using namespace std;

struct player
{
    int t;
    bool s;
};

int main()
{
    int j;
    int n,m;
    scanf("%d %d", &n, &m);
    int t;  int i;  bool s;
    bool check = true;
    struct player arr[n+1];

    for(j=1;j<=n;j++) {
        arr[j].t = 0;
        arr[j].s = true;
    }

    for(j=1;j<=m;j++) {
        scanf("%d %d", &t, &i); cin >> s;
        //cout << s;
        if (arr[i].s == s || (t - arr[i].t) < 60 )
            check = false;

        arr[i].t = t;
        arr[i].s = s;
    }

    if (check == true)
        for(j=1;j<=n;j++)
            if (arr[j].s == false)
                check=false;

    if (check == true)
        printf("YES");
    else
        printf("NO");

    return 0;
}
