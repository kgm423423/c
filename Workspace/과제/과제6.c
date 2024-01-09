#include <stdio.h>

int main()
{
    int i,j;
    float sum,arr[4][2];

    for(i=0;i<5;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }

    for(i=0,sum=0;i<5;i++)
    {
        if(arr[i][1]-arr[i][0]>1)
        {
            if(arr[i][1]-arr[i][0]>=5)
            {
                sum+=4;
            }
            else
            {
                sum+=arr[i][1]-arr[i][0];
            }
        }
    }

    if(sum>=15)
    {
        sum*=0.95;
    }
    else if(sum<=4)
    {
        sum*=1.05;
    }

    sum*=10000;

    printf("%d",(int)sum);

    return 0;
}
