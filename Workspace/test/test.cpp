#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Tag
{
    Tag_none,
    Tag_wall,
    Tag_player,
    Tag_endPoint,
};

struct Pos
{
    int x;
    int y;

};

int mapSize = 2;
int mazeSize;
int eyesight = 1000;
bool mapMade = false;

Tag** mapArr;
struct Pos playerPos;

bool makeMaze(int i, int j, bool** checkArr)
{
    if (i < 0 || i >= mapSize || j < 0 || j >= mapSize)
        return false;
    if (checkArr[i][j] == true)
        return false;

    checkArr[i][j] = true;

    int order[4] = {1,2,3,4};
    for (int k = 0; k < 4; k++)
	{
		int a = rand() % 4;
		int b = rand() % 4;

		int tmp = order[a];
		order[a] = order[b];
		order[b] = tmp;
	}

    int ii = (i*2)+1;
    int jj = (j*2)+1;

    for(int inex=0;inex<4;inex++) {
        switch(order[inex]){
        case 1:
            mapArr[ii+1][jj] = makeMaze(i+1,j, checkArr) ? Tag_none : Tag_wall;
            break;
        case 2:
            mapArr[ii][jj+1] = makeMaze(i,j+1, checkArr) ? Tag_none : Tag_wall;
            break;
        case 3:
            mapArr[ii-1][jj] = makeMaze(i-1,j, checkArr) ? Tag_none : Tag_wall;
            break;
        case 4:
            mapArr[ii][jj-1] = makeMaze(i,j-1, checkArr) ? Tag_none : Tag_wall;
            break;
        }
    }

    printf("test4\n");

    return true;
}

void makeMap()
{
    ///배열 할당 해제
    if (mapMade) {
        for(int i=0; i<mapSize; i++)
            delete[] mapArr[i];

        delete[] mapArr;
    }
    mapMade = true;


    ///배열 선언
    //미로
    mapArr = new Tag* [mazeSize];
    for(int i=0; i<mazeSize; i++)
        mapArr[i] = new Tag[mazeSize];

    //체크배열
    bool **checkArr;
    checkArr = new bool* [mapSize];
    for(int i=0; i<mapSize; i++)
        checkArr[i] = new bool[mapSize];

    ///배열 초기화
    for(int i=0;i<mapSize;i++)
        for(int j=0;j<mapSize;j++) {
            checkArr[i][j] = false;
        }
    for(int i=0;i<mazeSize;i++)
        for(int j=0;j<mazeSize;j++) {
            mapArr[i][j] = Tag_wall;
        }
    for(int i=1;i<mazeSize;i+=2)
        for(int j=1;j<mazeSize;j+=2) {
            mapArr[i][j] = Tag_none;
        }

    ///미로 생성
    printf("test1\n");
    makeMaze(1,1, checkArr);
    mapArr[1][1] = Tag_player;
    mapArr[mazeSize-1][mazeSize-2] = Tag_endPoint;
}

void playerMove(Pos nextPos)
{
    if (nextPos.x < 0 || nextPos.x >= mazeSize || nextPos.y < 0 || nextPos.y >= mazeSize)
        return;
    else if (mapArr[nextPos.y][nextPos.x] == Tag_wall)
        return;
    else
        playerPos = nextPos;
}

void input()
{
    char key = '\0';
    key = _getch();

    if (key != '\0') {
        mapArr[playerPos.y][playerPos.x] = Tag_none;
        switch (key) {
        case 'w':
            playerMove({playerPos.x, playerPos.y-1});
        break;
        case 'a':
            playerMove({playerPos.x-1, playerPos.y});
        break;
        case 's':
            playerMove({playerPos.x, playerPos.y+1});
        break;
        case 'd':
            playerMove({playerPos.x+1, playerPos.y});
        break;
        }

        mapArr[playerPos.y][playerPos.x] = Tag_player;
    }

}

void drawMap()
{
    system("cls");

    int xStart = playerPos.x - eyesight < 0 ? 0 : playerPos.x - eyesight;
    int xEnd = playerPos.x + eyesight > mazeSize-1 ? mazeSize-1 : playerPos.x + eyesight;
    int yStart = playerPos.y - eyesight < 0 ? 0 : playerPos.y - eyesight;
    int yEnd = playerPos.y + eyesight > mazeSize-1 ? mazeSize-1 : playerPos.y + eyesight;

    for(int i=yStart; i<=yEnd; i++) {
        for(int j = xStart; j<=xEnd; j++) {
            switch (mapArr[i][j]) {
                case Tag_none:
                printf("\033[38;2;%d;%d;%dm", 0, 0, 0);
                printf("0 ");
                break;
                case Tag_wall:
                printf("\033[38;2;%d;%d;%dm", 255, 255, 255);
                printf("0 ");
                break;
                case Tag_player:
                printf("\033[38;2;%d;%d;%dm", 255, 0, 0);
                printf("p ");
                break;
                case Tag_endPoint:
                printf("\033[38;2;%d;%d;%dm", 50, 255, 255);
                printf("e ");
                break;
            }
        }
        printf("\n");
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    mazeSize = (mapSize*2)+1;

    while (true) {
        makeMap();
        playerPos = {1,1};
        drawMap();

        while (playerPos.x != mazeSize-2 || playerPos.y != mazeSize-1) {
            drawMap();
            input();
        }

        mapSize++;
        mazeSize = (mapSize*2)+1;
    }







    return 0;
}
