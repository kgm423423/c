#include <stdio.h>

struct node
{
    int num;
    int gas;
};

void change(struct node *i, struct node *j)
{
    struct node k;
    k=*i;
    *i=*j;
    *j=k;
    return;
}

int main()
{
    int i, j, n;
    scanf("%d", &n);

    struct node arr[n];

    for(i=0;i<n;i++)
        scanf("%d %d", &arr[i].num, &arr[i].gas);

    for(i=1;i<n;i++)
        for(j=0;j<n-i;j++)
            if (arr[j].num>arr[j+1].num)
                change(&arr, &arr[j+1]);

    for(i=0;i<n;i++)
        printf("%d %d\n", arr[i].num, arr[i].gas);
}
