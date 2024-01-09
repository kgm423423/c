#include <stdio.h>

int main()
{
    int i,j;
    char arrChar[100];

    scanf("%s",&arrChar);

    for(i=0,j=0;arrChar[i]!='\0';i++) {
        if (j < (int)arrChar[i])
            j = arrChar[i];
    }

    printf("%c",j);

    return 0;
}
