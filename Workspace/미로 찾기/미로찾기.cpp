#include <stdio.h>
#include <windows.h>
#include <conio.h>

struct pos
{
    int x;
    int y;

};

const int mapSize = 10;
int eyesight = 100;
int mapArr[(mapSize*2)+1][(mapSize*2)+1] = {};
struct pos player = {1,1};

void input()
{
    char key = '\0';
    key = _getch();

    if (key != '\0') {
        mapArr[player.y][player.x] = 0;
        switch (key) {
        case 'w':
            player.y = player.y-1 < 0 ? player.y : player.y-1;
        break;
        case 's':
            player.y = player.y+1 > mapSize-1 ? player.y : player.y+1;
        break;
        case 'a':
            player.x = player.x-1 < 0 ? player.x : player.x-1;
        break;
        case 'd':
            player.x = player.x+1 > mapSize-1 ? player.x : player.x+1;
        break;
        default:
            printf("error\n");
            break;
        }

        mapArr[player.y][player.x] = 1;
    }

}

void mapLoad()
{
    system("cls");

    int xStart = player.x - eyesight < 0 ? 0 : player.x - eyesight;
    int xEnd = player.x + eyesight > mapSize-1 ? mapSize-1 : player.x + eyesight;
    int yStart = player.y - eyesight < 0 ? 0 : player.y - eyesight;
    int yEnd = player.y + eyesight > mapSize-1 ? mapSize-1 : player.y + eyesight;

    printf("%d %d\n\n", xStart, xEnd);

    for(int i=yStart; i<=yEnd; i++) {
        for(int j = xStart; j<=xEnd; j++) {
            switch (mapArr[i][j]) {
                case 0:
                printf("0");
                break;
                case 1:
                printf("p");
                break;
            }
        }
        printf("\n");
    }
}

int main()
{
    mapArr[0][0] = 1;

    while (true) {
        mapLoad();
        input();
    }











    return 0;
}
