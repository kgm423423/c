#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool check (int num)
{
    string str = to_string(num);
    string str2 = str;
    reverse(str2.begin(), str2.end());
    return !str.compare(str2);
}

int main()
{
    int n;
    const int m = 1003001;

    scanf("%d", &n);

    bool arr[m+1];

    for(int i=1;i<=m;i++)
        arr[i] = false;
    arr[1] = true;

    for(int i=2;i<=m;i++) {
        if (!arr[i]) {
            if (i >= n && check(i)) {
                printf("%d", i);
                break;
            }

            int j = i+i;

            while (j <= m) {
                arr[j] = true;
                j += i;
            }
        }
    }

    return 0;
}
