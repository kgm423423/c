#include <stdio.h>      //fin

int f(char k)
{
    if (k == 'A')
        return 1;
    else if (k == 'B')
        return 2;
    else if (k == 'C')
        return 3;
    else
        return 0;
}


int main()
{
    int i,j;
    int sum = 0;
    char k = '\0';

    int ABC[4] = {};

    while(k != '\n') {
        scanf("%c", &k);

        ABC[f(k)]++;

        if (ABC[1] == 2 || ABC[2] == 2 || ABC[3] == 2) {
            sum+=2;
            ABC[1] = 0; ABC[2] = 0; ABC[3] = 0;
        }
    }

    printf("%d", sum);

    return 0;
}
