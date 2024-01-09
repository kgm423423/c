#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

char arr[5][11] = {};

void f(int i, int j)
{
    if (i >= 5 || j >= 11 || arr[i][j] == 0 )
        return;


    f(i+1, j*2);

    printf("sum : %c \n", arr[i][j]);

    f(i+1, (j*2)+1);

    return;
}

int main()
{
    int n;
    int k = 97;
    int i,j;
    int h = 0;

    scanf("%d", &n);

    // 배열 만들기
    i=0;
    while (i < n) {
        j = 0;
        while (j < pow(2, h) && i < n) {
            arr[h][j] = (int)k;
            j++;
            i++;
            k++;
        }
        h++;
    }

    f(0,0);

    return 0;
}
