#include <stdio.h>

int main()
{
    int i,sum;
    char str[500];

    fgets(str, sizeof(str), stdin);

    for(i=sum=0;str[i]!=10;i++)
        sum+=str[i]-48;

    if (sum%3==0)
        printf("1");
    else
        printf("0");

    return 0;
}
