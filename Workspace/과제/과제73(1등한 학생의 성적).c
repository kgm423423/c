#include <stdio.h>

struct node
{
    char name[10];
    int num1;
    int num2;
    int num3;
};

void f(struct node arr[], int len)
{
    int i,j;
    struct node k;

    for(i=1;i<len;i++)
        for(j=0;j<len-i;j++)
            if (arr[j].num1 < arr[j+1].num1) {
                k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }

    return;
}

int main()
{
    int i,k;
    int n;
    scanf("%d", &n);
    struct node arr[n];

    for(i=0;i<n;i++)
        scanf("%s %d %d %d", arr[i].name, &arr[i].num1, &arr[i].num2, &arr[i].num3);

    f(arr, n);

    printf("%s ",arr[0].name);

    for(i=1,k=1;i<n;i++)
        if (arr[0].num2 < arr[i].num2)
            k++;

    printf("%d ", k);

    for(i=1,k=1;i<n;i++)
        if (arr[0].num3 < arr[i].num3)
            k++;

    printf("%d", k);

    return 0;
}
