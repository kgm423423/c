#include <stdio.h>

struct node
{
  char name[11];
  int score;
};

int main()
{
    int i,j,k;
    int n,m;
    scanf("%d %d ", &n, &m);
    struct node arr[n+1];

    for(i=1;i<n+1;i++)
        scanf("%s %d", arr[i].name, &arr[i].score);

    arr[0].score = -1;

    for(i=0;i<m;i++) {
        for(j=0,k=0;j<n;j++)
            if (arr[k].score < arr[j+1].score)
                k=j+1;

        printf("%s\n", arr[k].name);
        arr[k].score=0;
    }

    return 0;
}
