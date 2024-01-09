#include <stdio.h>      //fin

int main()
{
    int i,j;
    int s,e;
    int n;
    scanf("%d", &n);
    int arr[n];
    int sum=0;
    int t;
    scanf("%d", &t);

    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    s=0;e=0;
    while(s<n && e<n) {
        int m=0;
        for(i=s;i<=e;i++)
            m+=arr[i];
        if (m==t)
            sum++;
        if (m>=t)
            s++;
        else
            e++;

    }

    printf("%d", sum);

    return 0;
}
