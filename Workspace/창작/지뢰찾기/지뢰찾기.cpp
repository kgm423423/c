#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

struct Node
{
    bool checked;
    bool isBomb;
    int info;
};
struct Pos
{
    int y;
    int x;
};

bool gameover = false;
int mapSize;
Node** mapArr;
Pos selectedPos = {-1,-1};

bool checkBomb(int i, int j)
{
    if (i < 0 || i >= mapSize)
        return false;
    if (j < 0 || j >= mapSize)
        return false;

    return mapArr[i][j].isBomb ? true : false;
}

void makeArr(int mapSizeN)
{
    mapArr = new Node* [mapSizeN];

    for(int i=0; i<mapSizeN; i++)
            mapArr[i] = new Node[mapSizeN];

    return;
}

void makeMap()
{
    for(int i=0;i<mapSize;i++)
        for(int j=0;j<mapSize;j++) {
            mapArr[i][j].isBomb = false;
            mapArr[i][j].checked = false;
        }

    //make bomb
    int k = (mapSize*mapSize/6) + 1;
    while (k != 0) {
        int i = rand() % mapSize;
        int j = rand() % mapSize;

        if (mapArr[i][j].isBomb)
            continue;

        mapArr[i][j].isBomb = true;
        k--;
    }

    //info arr
    for(int i=0;i<mapSize;i++)
        for(int j=0;j<mapSize;j++) {
            mapArr[i][j].info =  checkBomb(i-1,j-1) + checkBomb(i-1,j) + checkBomb(i-1,j+1)
                                    +checkBomb(i,j-1) + checkBomb(i,j) + checkBomb(i,j+1)
                                +checkBomb(i+1,j-1) + checkBomb(i+1,j) + checkBomb(i+1,j+1);
        }
}

void drawMap()
{
    system("cls");

    //debug
    for(int i=0;i<mapSize;i++) {
        for(int j=0;j<mapSize;j++) {
            cout << mapArr[i][j].isBomb << " ";
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<mapSize;i++) {
        for(int j=0;j<mapSize;j++) {
            cout << mapArr[i][j].info << " ";
        }
        printf("\n");
    }
    printf("\n");


    for(int i=0;i<mapSize;i++) {
        for(int j=0;j<mapSize;j++) {
            if (mapArr[i][j].checked) {
                if (mapArr[i][j].info == 0)
                    printf("  ");
                else
                    printf("%d ", mapArr[i][j].info);
            }
            else
            printf("o ");
        }
        printf("\n");
    }

    return;
}

void input()
{
    scanf("%d %d", &selectedPos.x, &selectedPos.y);

    mapArr[selectedPos.y-1][selectedPos.x-1].checked = true;


    return;
}

int main()
{
    ///rand N
    srand((unsigned int)time(NULL));

    ///make Arr
    scanf("%d", &mapSize);
    makeArr(mapSize);
    makeMap();

    while (!gameover) {
        drawMap();
        input();
    }







    return 0;
}
