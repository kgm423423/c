#include <stdio.h>
int main()
{
    int arr[5][5],h,i=0,j=0,k=1,m=0,n=0,p=0;

    for(h=1;h<5*2;h++)
    {
        if(h%4==1)
        {
            for(j=m;j<5-n;j++,k++)
            {
                arr[i][j]=k;
            }
            j--;
        }
        else if(h%4==2)
        {
            for(i=m;i<5-n;i++,k++)
            {
                arr[i][j]=k;
            }
            i--;
        }
        else if(h%4==3)
        {
            for(j=5-m-1;j>=n;j--,k++)
            {
                arr[i][j]=k;
            }
            j++;
        }
        else
        {
            for(i=5-m-1;i>=n;i--,k++)
            {
                arr[i][j]=k;
            }
            i++;
        }

        if(h%2==1)
        {
            p++;
            if(p%2==0)
            {
                n++;
            }
            else
            {
                m++;
            }
        }
    }

    printf("\n");

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
