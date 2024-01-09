#include <stdio.h>
#include <string.h>

int main()
{
    int i,j;
    int n;
    scanf("%d", &n);
    char arr[n][21];
    char k[21];

    getchar();

    for(i=0;i<n;i++)
        scanf("%s", arr[i]);

    for(i=1;i<n;i++) {
        for(j=0;j<n-i;j++) {
            if (strcmp(arr[j], arr[j+1]) == 1) {
                strcpy(k, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], k);
            }
        }
    }

    for(i=0;i<n;i++)
        printf("%s\n", arr[i]);

    return 0;
}
