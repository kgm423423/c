#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int m;
    scanf("%d", &n);
    m = sqrt(n);
    bool arr[n+1];
    int i,j,k;
    int sum = 0;

    for(i=1;i<=n;i++)
        arr[i] = false;
    arr[1] = true;

    for(i=1, j=1; i<m; i++) {
        while (arr[j])
            j++;

        k = 2;
        while (j*k <= n) {
            if (arr[j*k]) {
                k++;
                continue;
            }
            //printf("%d %d %d %d\n", j*k, i, j, k);

            arr[j*k] = true;
            k++;
            sum++;
        }
        j++;
    }

    //for(i=2;i<=n;i++)
        //if (!arr[i])
            //printf("%d ", i);

    printf("sum : %d", n-sum-1);



    return 0;
}
