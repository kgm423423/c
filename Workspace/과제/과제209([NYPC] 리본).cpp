#include <stdio.h>
#include <math.h>

using namespace std;

struct node
{
    int index;
    int length;
    int point;
};

struct node arr[151];

int sum = 0;;

void f(int x, int fSum)
{
    if (x > n) {
        if (fSum > sum)
            sum = fSum;
        return;
    }

    for(int i=x; i<=n; i++) {
        int h = arr[i].index - arr[x].index;

        if (h < 0)
            continue;

        int v = (arr[i].length + arr[x].length - h)/2;

        if (v)
    }



}


int main()
{
    int i,j;
    int n;

    //배열 입력받기
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d %d %d", &arr[i].index, &arr[i].length, &arr[i].point);

    //정렬
    for(i=n;i>1;i--)
        for(j=1;j>i;j++)
            if (arr[j].index > arr[j+1].index) {
                struct node k = arr[j].index;
                arr[j].index = arr[j+1].index;
                arr[j+1].index = k;
            }

    //재귀함수
    f(1, 0);

    return 0;
}
