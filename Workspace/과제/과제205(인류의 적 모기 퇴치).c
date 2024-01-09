#include <stdio.h>      //fin

int n,m;
int arr[50][50];

int f(int i, int posY, int posX, int dircY, int dircX)
{
    if (i > m || posX < 0 || posX >= n || posY < 0 || posY >= n)
        return 0;

    return arr[posY][posX] + f(i+1, posY+dircY, posX+dircX, dircY, dircX);
}

int main()
{
    int i,j;
    int sum = 0;
    scanf("%d %d", &n, &m);


    //배열 입력받기
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &arr[i][j]);

    //계산
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
            int sum1 = arr[i][j] +  f(1, i+1, j, 1, 0) + f(1, i-1, j, -1, 0) + f(1, i, j+1, 0, 1) + f(1, i, j-1, 0, -1);
            int sum2 = arr[i][j] +  f(1, i+1, j-1, 1, -1) + f(1, i+1, j+1, 1, 1) + f(1, i-1, j-1, -1, -1) + f(1, i-1, j+1, -1, 1);

            if (sum < sum1)
                sum = sum1;
            if (sum < sum2)
                sum = sum2;
        }

    printf("%d", sum);

    return 0;
}
