#include <stdio.h>
int main()
{
    int arr[5][5],i,j,k,m;

    for(i=0,k=1,m=1;i<5;i++,m++)
    {
        if(m%2==0)
        {
            for(j=4;j>=0;j--,k++)
            {
                arr[i][j]=k;
            }
        }
        else
        {
            for(j=0;j<5;j++,k++)
            {
                arr[i][j]=k;
            }
        }

    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%-3d",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
