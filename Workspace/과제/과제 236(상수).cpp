#include <stdio.h>

int input()
{
    char n1, n2, n3;

    scanf("%c%c%c", &n1, &n2, &n3);

    return ((n3-48)*100) + ((n2-48)*10) + (n1-48);
}


int main()
{
    int n1 = input();
    getchar();
    int n2 = input();

    printf("%d", n1 > n2 ? n1 : n2);

    return 0;
}
