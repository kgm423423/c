#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

enum Tag
{
    Tag_none,
    Tag_wall,
    Tag_player,
    Tag_endPoint,
    Tag_item_eyelevelUp,
    Tag_enemy,
};

struct Pos
{
    int x;
    int y;

};

int debug=0;

int chance = 0;
int mapSize = 1;
int mazeSize;
int eyelevel = 3;
bool mapMade = false;
bool gameover = false;


Tag** mapArr;
Pos playerPos;
Pos enemyPos;
vector<Pos> route;

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
    int corner = 0;

    for(int inex=0;inex<4;inex++) {
        switch(order[inex]){
        case 1:
            if (makeMaze(i+1,j, checkArr)) {
                mapArr[ii+1][jj] = Tag_none;
            }
            else
                corner++;
            break;
        case 2:
            if (makeMaze(i,j+1, checkArr)) {
                mapArr[ii][jj+1] = Tag_none;
            }
            else
                corner++;
            break;
        case 3:
            if (makeMaze(i-1,j, checkArr)) {
                mapArr[ii-1][jj] = Tag_none;
            }
            else
                corner++;
            break;
        case 4:
            if (makeMaze(i,j-1, checkArr)) {
                mapArr[ii][jj-1] = Tag_none;
            }
            else
                corner++;
            break;
        }
    }

    if (corner == 4) {
        int randum = rand()%10;

        if (randum == 0 || randum == 1)
            mapArr[ii][jj] = Tag_item_eyelevelUp;
    }

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
    else if (mapArr[nextPos.y][nextPos.x] == Tag_item_eyelevelUp)
        eyelevel++;

    playerPos = nextPos;
}

void input()
{
    int key = _getch();

    mapArr[playerPos.y][playerPos.x] = Tag_none;
	if (key == 224) {
		key = _getch();
		switch (key) {
        case 72: playerMove({playerPos.x, playerPos.y-1}); break;
        case 75: playerMove({playerPos.x-1, playerPos.y}); break;
        case 77: playerMove({playerPos.x+1, playerPos.y}); break;
        case 80: playerMove({playerPos.x, playerPos.y+1}); break;
		}
	}
    else {
        ///영문 입력
        switch (key) {
        case 'w': playerMove({playerPos.x, playerPos.y-1}); break;
        case 'a': playerMove({playerPos.x-1, playerPos.y}); break;
        case 'd': playerMove({playerPos.x+1, playerPos.y}); break;
        case 's': playerMove({playerPos.x, playerPos.y+1}); break;
        }
    }

    mapArr[playerPos.y][playerPos.x] = Tag_player;
}

void drawMap()
{
    int xStart = playerPos.x - eyelevel < 0 ? 0 : playerPos.x - eyelevel;
    int xEnd = playerPos.x + eyelevel > mazeSize-1 ? mazeSize-1 : playerPos.x + eyelevel;
    int yStart = playerPos.y - eyelevel < 0 ? 0 : playerPos.y - eyelevel;
    int yEnd = playerPos.y + eyelevel > mazeSize-1 ? mazeSize-1 : playerPos.y + eyelevel;

    for(int i=yStart; i<=yEnd; i++) {
        for(int j = xStart; j<=xEnd; j++) {
            switch (mapArr[i][j]) {
                case Tag_none:
                printf("  ");
                break;
                case Tag_wall:
                if (chance == 0)
                    printf("\033[38;2;%d;%d;%dm", 155, 0, 0);
                else
                    printf("\033[38;2;%d;%d;%dm", 255, 255, 255);
                printf("1 ");
                break;
                case Tag_player:
                printf("\033[38;2;%d;%d;%dm", 0, 255, 255);
                printf("p ");
                break;
                case Tag_endPoint:
                printf("\033[38;2;%d;%d;%dm", 0, 255, 255);
                printf("e ");
                break;
                case Tag_item_eyelevelUp:
                printf("\033[38;2;%d;%d;%dm", 0, 255, 255);
                printf("i ");
                break;
                case Tag_enemy:
                printf("\033[38;2;%d;%d;%dm", 255, 0, 0);
                printf("x ");
                break;
            }
        }
        printf("\n");
    }
}

void drawUI()
{
    system("cls");

    printf("\033[38;2;%d;%d;%dm", 255, 255, 255);
    printf("[Stage : %d]\n\n",mapSize);
    printf("%d\n",debug);

    drawMap();
}

void enemyMove()
{
    ///이동경로 지정
    route.push_back(playerPos);
    Pos currentPos;

    if (route.size() > 1) {
        currentPos = route[route.size()-2];
        if (playerPos.x == currentPos.x && playerPos.y == currentPos.y)
            route.pop_back();
    }
    if (route.size() > 2) {
        currentPos = route[route.size()-3];
        if (playerPos.x == currentPos.x && playerPos.y == currentPos.y) {
            route.pop_back();
            route.pop_back();
        }
    }

    if (chance != 0)
        return;

    ///이동
    currentPos = route.front();
    route.erase(route.begin());

    mapArr[enemyPos.y][enemyPos.x] = Tag_none;
    mapArr[currentPos.y][currentPos.x] = Tag_enemy;
    enemyPos.x = currentPos.x; enemyPos.y = currentPos.y;

    ///게임오버
    if (playerPos.x == enemyPos.x && playerPos.y == enemyPos.y)
        gameover = true;
}

int main()
{
    srand((unsigned int)time(NULL));
    mazeSize = (mapSize*2)+1;


    do {
        chance = 100;
        makeMap();
        playerPos = {1,1};
        enemyPos = {1,1};
        route.clear();
        drawUI();

        while (playerPos.x != mazeSize-2 || playerPos.y != mazeSize-1 && !gameover) {
            input();
            enemyMove();
            drawUI();
            debug = chance;
            chance = chance == 0 ? 0 : chance-1;
        }

        mapSize++;
        mazeSize = (mapSize*2)+1;
    } while (!gameover);

    system("cls");

    printf("\033[38;2;%d;%d;%dm", 255, 255, 255);
    printf("Gameover\n");
    printf("[Max Stage : %d]\n\n",mapSize-1);

    return 0;
}
