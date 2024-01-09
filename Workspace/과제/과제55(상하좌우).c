#include <stdio.h>

int main()
{
    int x=1, y=1, n;
    char m[201];

    fgets(n, 4, stdin);
    fgets(m, 201, stdin);

    for(int i=0;i<201 && m[i]!='\0';i+=2) {
        if (m[i]=='L' && x>1)
            x--;
        if (m[i]=='R' && x<n)
            x++;
        if (m[i]=='U' && y>1)
            y--;
        if (m[i]=='D' && y<n)
            y++;
    }

    printf("%d %d", y, x);

    return 0;
}
