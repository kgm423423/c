#include <stdio.h>      //fin

const int INF = 999999999;

int main()
{
    int i,j,k;
    int arr[4][4] = {   {0,4,INF,6},
                        {3,0,7,INF},
                        {5,INF,0,4},
                        {INF,INF,2,0}
                     };

    for(k=0;k<4;k++) {
        for(i=0;i<4;i++) {
            if (i==k)
                continue;
            for(j=0;j<4;j++) {
                if (j==i || j==k)
                    continue;

                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    //Ãâ·Â
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }


    return 0;
}
