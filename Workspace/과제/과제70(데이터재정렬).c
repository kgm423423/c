#include <stdio.h>

struct node
{
    int num;
    int rank;
};

int main()
{
    int i, j, n;
    scanf("%d", &n);

    struct node arr[n];

    for(i=0;i<n;i++) {
        scanf("%d", &arr[i].num);
        arr[i].rank=0;
    }


    for(i=0;i<n;i++) {
        for(j=0;j<n;j++)
            if (arr[i].num<arr[j].num)
                arr[j].rank++;
    }

    for(i=0;i<n;i++)
        printf("%d ", arr[i].rank);

    return 0;
}
