#include <stdio.h>

int f(char arr[])
{
    int i,len;

    for(i=0,len=0;arr[i]!='\0';i++)
    {
        len++;
    }

    for(i=0;i<len/2;i++) {
        if (arr[i]!=arr[len-i-1])
            return 0;
    }

    return 1;
}

int main()
{
    char arr[100];
    scanf("%s",&arr);

    if (f(arr)==1)
        printf("회문 입니다.");

    return 0;
}
