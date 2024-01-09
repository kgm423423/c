#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF = 999999999;
int sum = INF;

int n,m;
int arr[101];

void f(int num, int i)
{
    if (i > sum || num > m) {
        return;
    }
    else if (num == m) {
        if (i < sum) {
            printf("%d\n", sum);
            sum = i;
        }
        return;
    }
    else {
        for(int j=0;j<n;j++) {
            f(num+arr[j], i+1);
        }
        return;
    }
}

void f2(int num,int index, int i)
{
    if (i > sum || index == n || num > m) {
        return;
    }
    else if (num == m) {
        if (i < sum) {
            printf("%d\n", sum);
            sum = i;
        }
        return;
    }
    else {
        for(int j=index;j<n;j++) {
            f2(num+arr[j],j,i+1);
        }
        return;
    }


}

int main()
{
    scanf("%d %d", &n, &m);


    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    for(int i=n-1;i>0;i--)
        for(int j=0;j<i;j++)
            if (arr[j+1] > arr[j])
                swap(arr[j+1], arr[j]);

    //f(0,0);
    f2(0,0,0);

    if (sum == INF)
        printf("-1");
    else
        printf("%d", sum);

    return 0;
}
