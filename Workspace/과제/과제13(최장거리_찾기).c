#include <stdio.h>
#include <math.h>

struct pos pos1,pos2;
double dis=0;

struct pos
{
    int x;
    int y;
};

void f(struct pos n1, struct pos n2)

{   //printf("%lf", pow(n1.x - n2.x ,2));
    double k = sqrt(pow(n1.x - n2.x ,2)+pow(n1.y-n2.y,2));
    //printf("%lf\n", k);

    if (dis < k) {
        dis = k;
        pos1 = n1;
        pos2 = n2;
    }

    return;
}

int main()
{
    int i,j;
    int n;
    scanf("%d", &n);
    struct pos arr[n];

    for(i=0;i<n;i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            f(arr[i], arr[j]);

    printf("%.2lf\n", dis);
    if (pos1.x > pos2.x) {
        printf("(%d,%d)\n", pos1.x, pos1.y);
        printf("(%d,%d)\n", pos2.x, pos2.y);
    }
    else if (pos1.x < pos2.x) {
        printf("(%d,%d)\n", pos2.x, pos2.y);
        printf("(%d,%d)\n", pos1.x, pos1.y);
    }
    else {
        if (pos1.y >= pos2.y) {
            printf("(%d,%d)\n", pos1.x, pos1.y);
            printf("(%d,%d)\n", pos2.x, pos2.y);
        }
        else {
            printf("(%d,%d)\n", pos2.x, pos2.y);
            printf("(%d,%d)\n", pos1.x, pos1.y);
        }
    }

    return 0;
}
