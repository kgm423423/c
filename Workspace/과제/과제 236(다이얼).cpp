#include <stdio.h>

int input(char k)
{
    if (k <= 'C')
        return 3;
    else if (k <= 'F')
        return 4;
    else if (k <= 'I')
        return 5;
    else if (k <= 'L')
        return 6;
    else if (k <= 'O')
        return 7;
    else if (k <= 'S')
        return 8;
    else if (k <= 'V')
        return 9;
    else if (k <= 'Z')
        return 10;
    else
        return 0;

}

int main()
{
    int sum = 0;
    char k;

    scanf("%c", &k);
    while (k != '\n') {
        sum += input(k);
        scanf("%c", &k);
    }

    printf("%d", sum);

    return 0;
}
