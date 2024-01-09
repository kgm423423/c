#include  <stdio.h>     //fin

int main()
{
    int i,j;
    int n,k;
    int sum = 0;
    scanf("%d %d", &n, &k);
    char arr[n];
    scanf("%s", arr);

    for(i=0;i<n;i++) {
        if (arr[i] == 'P') {
            if (i<k)
                j = 0;
            else
                j = i-k;

                while (j < n && j <= i+k) {
                    if (arr[j] == 'H') {
                        sum++;
                        arr[j] = 'h';
                        break;
                    }
                    j++;
                }
        }
    }

    printf("%d", sum);



    return 0;
}
