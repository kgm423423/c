#include <stdio.h>

int main()
{
    int i,j;
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[n];
    int sum = 0;

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    for(i=0;i<n;i++) {
        int k = 0;
        for(j=i;j<n;j++) {
            k += arr[j];
            if (k%m == 0) {
                printf("%d ~ %d\n", i, j);
                sum++;
            }
        }
    }

    printf("%d", sum);







    return 0;
}
