#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

struct Cell
{
     ///포지션
    int x;
    int y;
    int dir;


    ///특성
    int speed = 0;
    int life = 0;
    int _size = 0;
};

struct mapNode
{
    bool check;
    struct Cell cell;
};

const int mapSize = 10;
const int respawnDelay = 10;
const int maxStat = 100;

mapNode mapArr[mapSize][mapSize] = {};
int gameTime = 0;

void moveTo(Cell newCell, int i, int j)
{
    if (i < 0 || i >= mapSize || j < 0 || j >= mapSize)
        return;
    else if (mapArr[i][j].check) {
        Cell oldCell = mapArr[i][j].cell;

        if (oldCell._size == newCell._size) {
            switch (newCell.dir) {
                case 0:
                moveTo(oldCell, i+1, j);
                break;
                case 1:
                moveTo(oldCell, i, j+1);
                break;
                case 2:
                moveTo(oldCell, i-1, j);
                break;
                case 3:
                moveTo(oldCell, i, j-1);
                break;
            }
        }
        else if (oldCell._size > newCell._size)
            newCell = oldCell;
        else if (oldCell._size > newCell._size)
            oldCell = newCell;
    }
    mapArr[i][j].cell = newCell;
    mapArr[i][j].check = true;
}

void makeCell(Cell newCell)
{
    int i = newCell.y;
    int j = newCell.x;

    moveTo(newCell, i, j);
}

void respawn()
{
    if (gameTime % respawnDelay == 0) {
        srand((unsigned int)time(NULL));

        ///세포 생성
        Cell newCell;

        ///포지션 설정
        int i = rand() % mapSize;
        int j = rand() % mapSize;
        newCell.x = j;
        newCell.y = i;
        newCell.dir = rand() % 4;

        ///스탯 배분
        int stat = maxStat;
        while (stat > 0)  {

            int point = (rand() % stat) +1;

            int x = rand() % 3;
            switch (x) {
                case 0:
                newCell.speed += point;
                break;
                case 1:
                newCell.life += point;
                break;
                case 2:
                newCell._size += point;
                break;
            }
            stat -= point;
        }

        makeCell(newCell);
    }
}

void cellMove()
{
    for(int i=0;i<mapSize;i++)
        for(int j=0;j<mapSize;j++)
            if (mapArr[i][j].check) {
                Cell cell = mapArr[i][j].cell;
                if (cell.speed != 0 && gameTime % (maxStat - cell.speed) == 0) {
                    mapArr[i][j].check = false;

                    switch (cell.dir) {
                            case 0:
                            moveTo(cell, i+1, j);
                            break;
                            case 1:
                            moveTo(cell, i, j+1);
                            break;
                            case 2:
                            moveTo(cell, i-1, j);
                            break;
                            case 3:
                            moveTo(cell, i, j-1);
                            break;
                    }
                }
            }



}

void drawMap()
{
    system("cls");

    for(int i=0;i<mapSize;i++) {
        for(int j=0;j<mapSize;j++) {
            if (mapArr[i][j].check) {
                Cell cell = mapArr[i][j].cell;
                int r = cell.speed *2.55;
                int g = cell.life *2.55;
                int b = cell._size *2.55;
                printf("\033[38;2;%d;%d;%dm", r, g, b);
                printf("o");
            }
            else {
                printf("\033[38;2;%d;%d;%dm", 255, 255, 255);
                printf("-");
            }
        }
        printf("\n");
    }
}


int main()
{
    ///배열 초기화
    for(int i = 0; i < mapSize; i++)
        for(int j = 0; j < mapSize; j++)
            mapArr[i][j].check = false;

    ///게임 시작
    while (true) {
        respawn();
        drawMap();


        ///시간 경과
        printf("time : %d\n", gameTime);
        gameTime++;
        Sleep(10);
    }

    return 0;
}
