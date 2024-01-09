#include <stdio.h>

int main()
{
    int i;
    char arr[11];

    scanf("%s",arr);
    for(i=0;arr[i]!='\0';i++) {
        if (arr[i] == 't')
            printf("%d ",i+1);
    }

    return 0;
}
