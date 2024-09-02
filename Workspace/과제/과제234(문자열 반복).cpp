#include <stdio.h>

int main()
{
    int n,m;
    char input[21];

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &m);

        getchar();
        char k = '\0';
        scanf("%c", &k);
        while (k!='\n') {
            for(int j=0;j<m;j++)
                printf("%c", k);
            scanf("%c", &k);
        }
        printf("\n");
    }


    return 0;
}
