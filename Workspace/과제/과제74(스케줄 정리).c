#include <stdio.h>

struct node
{
    char w[100];
    int y;
    int m;
    int d;
    unsigned int num;
};

void f(struct node arr[], int len)
{
    int i,j;
    struct node k;

    for(i=1;i<len;i++)
        for(j=0;j<len-i;j++)
            if (arr[j].num > arr[j+1].num) {
                k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }

    return;
}

int main()
{
    int i,j,k;
    int n;
    scanf("%d", &n);
    struct node arr[n];

    for(i=0;i<n;i++) {
        scanf("%s %d %d %d", arr[i].w, &arr[i].y, &arr[i].m, &arr[i].d);
        arr[i].num =  arr[i].y*10000 + arr[i].m*100 + arr[i].d;
    }

    f(arr, n);

    for(i=0;i<n;i++)
        printf("%s\n",arr[i].w);

    return 0;
}
