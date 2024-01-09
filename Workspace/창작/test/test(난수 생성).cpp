#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void f()
{
    //srand(time(NULL));
    int card[4] = {1,2,3,4};

    for (int i = 0; i < 4; i++)
	{
		int a = rand() % 4;
		int b = rand() % 4;

		int tmp = card[a];
		card[a] = card[b];
		card[b] = tmp;
	}

    for(int i=0;i<4;i++)
        printf("%d", card[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL));

    while(true) {
        f();
        Sleep(100);
    }





    return 0;
}
