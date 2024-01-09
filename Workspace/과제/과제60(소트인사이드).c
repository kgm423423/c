#include <stdio.h>

void arrPrint(char arr[])
{
    int i;
    for(i=0;i<10 && arr[i]!='\0';i++)
    {
        if(arr[i]==0)
            printf(0);
        else
            printf("%c",arr[i]);
    }
    printf("\n");
}

int main()
{
    char arr[10];
    int i,j,k;
    char m;

    scanf("%s",arr);

    for(i=1;i<10 && arr[i]!='\0';i++)
    {
        for(j=0;j<i;j++)
        {
            if (arr[i]>=arr[j])
                {
                    m=arr[i];
                    for(k=i;k>j;k--)
                        arr[k]=arr[k-1];
                    arr[j]=m;
                }
        }

    }

    arrPrint(arr);

    return 0;
}
