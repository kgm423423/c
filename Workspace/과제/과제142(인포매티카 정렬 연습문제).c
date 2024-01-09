#include <stdio.h>

struct node
{
    char str[101];
    int p;

};

int main()
{
    int i,j;
    int n;
    int k;
    scanf("%d", &n);

    getchar();

    struct node arr[n];

    for(i=0;i<n;i++) {
        scanf("%s", arr[i].str);

        j = 0;
        while (arr[i].str[j] != '\0') {
            j++;
        }

        arr[i].p = arr[i].str[j-1];
    }

    for(i=1;i<n;i++) {
        for(j=0;j<n-i;j++) {
            if (arr[j].p > arr[j+1].p) {
                struct node q = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = q;
            }
        }
    }

    for(i=0;i<n;i++)
        printf("%s ", arr[i].str);

    return 0;
}
