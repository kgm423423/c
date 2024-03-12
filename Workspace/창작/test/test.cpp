#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main(void)
{
    int key = _getch();

    if (key == '\n')
        printf("enter");
    else
        printf("%d", key);

	return 0;
}
