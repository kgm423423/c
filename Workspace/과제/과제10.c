#include <stdio.h>
#include <math.h>

int main()
{
    int i,j,k,n,s,e;
    char d=0;

    scanf("%d %d",&s,&e);


    for(;s<=e;s++)
    {
        n=s;
        if(n>=100)
        {
            i=2;
        }
        else if(n>=10)
        {
            i=1;
        }
        else
        {
            i=0;
        }

       for(d=0;i>=0;i--)
       {
           k=pow(10,i);
           if(n/k==3||n/k==6||n/k==9)
           {
               d=1;
           }

           if(d==1)
           {
               break;
           }
           n -=n/k*k;
       }

       if(d==1)
       {
           printf("¦\n");
       }
       else
       {
           printf("%d\n",s);
       }
    }

    return 0;
}
