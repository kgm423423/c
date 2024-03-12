#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int main(void)
{
    while (true) {
         int key = _getch();
         system("mode con: cols=100 lines=50");
        printf("%d\n", key);
    }



	return 0;
}
