#include <stdio.h>
int main()
{
    int i,j,k=1,n,arr1[5][5],arr2[5][5]={0};

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i==0)
            {
                arr2[i][j]+=arr1[i+1][j];
            }
            else if(i==4)
            {
                arr2[i][j]+=arr1[i-1][j];
            }
            else
            {
                arr2[i][j]+=arr1[i+1][j]+arr1[i-1][j];
            }

            if(j==0)
            {
                arr2[i][j]+=arr1[i][j+1];
            }
            else if(j==4)
            {
                arr2[i][j]+=arr1[i][j-1];
            }
            else
            {
                arr2[i][j]+=arr1[i][j-1]+arr1[i][j+1];
            }
        }
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%-3d",arr1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%-3d",arr2[i][j]);
        }
        printf("\n");
    }


    return 0;
}
