#include <stdio.h>

struct node
{
    int t;
    int p;
};

int main()
{
    int i,j;
    int n;
    int sum = 0;
    scanf("%d", &n);
    struct node arr[n+2];


    //배열 입력받기
    for(i=1;i<=n;i++)
        scanf("%d %d", &arr[i].t, &arr[i].p);

    arr[n+1].p = 0;


    //계산하기
    for(i=n;i>0;i--) {
        if (i + arr[i].t > n+1)
            arr[i].p = 0;
        else {
            if (arr[i+1].p > arr[i].p + arr[i+arr[i].t].p)
                arr[i].p = arr[i+1].p;
            else
                arr[i].p = arr[i].p + arr[i+arr[i].t].p;
        }
    }



    //답 구하기
    for(i=1;i<=n;i++)
        if (arr[i].p > sum)
                sum = arr[i].p;

    printf("%d", sum);

    return 0;
}
