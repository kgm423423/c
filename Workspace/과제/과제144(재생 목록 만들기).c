#include <stdio.h>
#include <string.h>

struct node
{
    char name[31];
    int m;
    int s;
};

void swap(struct node* a, struct node* b)
{
	struct node temp = *a;
	*a = *b;
	*b = temp;

	return;
}

void scanStr(struct node arr[], int i)
{
    int j=0;
    char k = '\0';
    while (k != '\n') {
        scanf("%c", &k);
        arr[i].name[j] = k;
        j++;
    }

    arr[i].name[j-1] = '\0';

    return;
}

int main()
{
    int i,j;
    int n;
    char m;
    scanf("%d", &n);
    struct node arr[n];

    getchar();

    for(i=0;i<n;i++) {
        scanStr(arr,i);
        scanf("%d %d", &arr[i].m, &arr[i].s);
        getchar();
    }

    getchar();getchar();getchar();
    scanf("%c", &m);

    if (m == 'n')
        for(i=1;i<n;i++)
            for(j=0;j<n-i;j++)
                if (arr[j].name[0] > arr[j+1].name[0])
                    swap(&arr[j],&arr[j+1]);

    if (m == 'p')
        for(i=1;i<n;i++)
            for(j=0;j<n-i;j++)
                if ((arr[j].m*60)+arr[j].s < (arr[j+1].m*60)+arr[j+1].s)
                    swap(&arr[j],&arr[j+1]);

    for(i=0;i<n;i++) {
        printf("%s\n", arr[i].name);
        printf("%d ",m);
        if (arr[i].s < 10)
            printf("0");
        printf("%d\n",arr[i].s);
    }

    return 0;
}
