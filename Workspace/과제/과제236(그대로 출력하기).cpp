#include <stdio.h>

int main()
{
    char k = '\0';

    do {
        printf("%c", k);
        scanf("%c", &k);
    }while (k != EOF);


    return 0;
}
