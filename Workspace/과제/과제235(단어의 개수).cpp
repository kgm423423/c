#include <stdio.h>
int main()
{
    int sum = 0;
    char k = '\0';

   while (k!='\n') {
        scanf("%c", &k);
        if (k==' ')
            continue;
        else if (k == '\n')
            break;

        while (k != ' ' && k != '\n')
            scanf("%c", &k);
        sum++;
   }

    printf("%d", sum);


    return 0;
}
