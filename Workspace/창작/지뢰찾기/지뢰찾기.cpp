#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

struct Node
{
    bool flag;
    bool checked;
    bool isBomb;
    int info;
};
struct Pos
{
    int y;
    int x;
};

bool gameover;
int mapSize;
Node** mapArr;
Pos selectedPos;
int uncheckedSpace;
bool mapMade;

bool checkBomb(int i, int j)
{
    if (i < 0 || i >= mapSize)
        return false;
    if (j < 0 || j >= mapSize)
        return false;

    return mapArr[i][j].isBomb ? true : false;
}

void f(int posX, int posY)
{
    if (posX < 0 || posY < 0)
        return;
    if (posX >= mapSize || posY >= mapSize)
        return;
    if (mapArr[posY][posX].checked)
        return;

    mapArr[posY][posX].checked = true;
    uncheckedSpace--;

    if (mapArr[posY][posX].info == 0) {
        f(posX-1,posY-1); f(posX,posY-1); f(posX+1,posY-1);
        f(posX-1,posY);                   f(posX+1,posY);
        f(posX-1,posY+1); f(posX,posY+1); f(posX+1,posY+1);
    }

    return;
}

void select(int posX, int posY)
{
    if (posX < 0 || posY < 0)
        return;
    if (posX >= mapSize || posY >= mapSize)
        return;

    selectedPos.x = posX;
    selectedPos.y = posY;

    return;
}

void makeArr(int mapSizeN)
{
    if (mapMade) {
        for(int i=0; i<mapSize; i++)
            delete[] mapArr[i];

        delete[] mapArr;
    }
    mapMade = true;

    mapArr = new Node* [mapSizeN];

    for(int i=0; i<mapSizeN; i++)
            mapArr[i] = new Node[mapSizeN];

    return;
}

void makeMap()
{
    //initialization
    for(int i=0;i<mapSize;i++)
        for(int j=0;j<mapSize;j++) {
            mapArr[i][j].isBomb = false;
            mapArr[i][j].checked = false;
            mapArr[i][j].flag = false;
        }

    //make bomb
    uncheckedSpace = mapSize*mapSize;
    int k = (uncheckedSpace/8) + 1;
    while (k != 0) {
        int i = rand() % mapSize;
        int j = rand() % mapSize;

        if (mapArr[i][j].isBomb)
            continue;

        mapArr[i][j].isBomb = true;
        k--;
        uncheckedSpace--;
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

    ////////////////////////////////debug
    /*
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
    */
    /////////////////////////////////

    for(int i=0;i<mapSize;i++) {
        for(int j=0;j<mapSize;j++) {
            if (selectedPos.y == i && selectedPos.x == j)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

            if (!mapArr[i][j].flag) {
                if (mapArr[i][j].checked) {
                    if (mapArr[i][j].info == 0)
                        printf("_ ");
                    else
                        printf("%d ", mapArr[i][j].info);
                }
                else
                printf("o ");
            }
            else
                printf("x ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        printf("\n");
    }

    printf("left : %d", uncheckedSpace);

    return;
}

void input()
{
    int key = _getch();

    if (key == 13) {
        if (mapArr[selectedPos.y][selectedPos.x].flag)
            return;
        else if (mapArr[selectedPos.y][selectedPos.x].isBomb)
            gameover = true;
        else
            f(selectedPos.x,selectedPos.y);
    }
    else if (key == 32) {
        mapArr[selectedPos.y][selectedPos.x].flag = !mapArr[selectedPos.y][selectedPos.x].flag;
    }
	else if(key == 224) {
		key = _getch();
		switch (key) {
        case 72: select(selectedPos.x, selectedPos.y-1); break;
        case 75: select(selectedPos.x-1, selectedPos.y); break;
        case 77: select(selectedPos.x+1, selectedPos.y); break;
        case 80: select(selectedPos.x, selectedPos.y+1); break;
		}
	}
    else{
        switch (key) {
        case 'w': select(selectedPos.x, selectedPos.y-1); break;
        case 'a': select(selectedPos.x-1, selectedPos.y); break;
        case 'd': select(selectedPos.x+1, selectedPos.y); break;
        case 's': select(selectedPos.x, selectedPos.y+1); break;

        case 'W': select(selectedPos.x, selectedPos.y-1); break;
        case 'A': select(selectedPos.x-1, selectedPos.y); break;
        case 'D': select(selectedPos.x+1, selectedPos.y); break;
        case 'S': select(selectedPos.x, selectedPos.y+1); break;
        }
    }

    return;
}

int main()
{
    ///rand N
    srand((unsigned int)time(NULL));
    SetConsoleTitle(TEXT("지뢰찾기"));

    bool restart = true;

    while (restart) {
        system("cls");
        gameover = false;
        selectedPos = {0,0};
        mapMade = false;

        ///make Arr
        system("cls");
        printf("맵 사이즈 선택 : ");
        scanf("%d", &mapSize);
        makeArr(mapSize);
        makeMap();

        while (!gameover && uncheckedSpace != 0) {
            drawMap();
            input();
        }
        system("cls");

        if (uncheckedSpace == 0)
            printf("win");
        else
            printf("gameover");

        while(true) {
            int key = _getch();
            system("cls");
            printf("다시시작 (Y/N)\n");

            if (key == 121 || key == 89) {
                restart = true;
                break;
            }
            else if (key == 110 || key == 78) {
                restart = false;
                break;
            }
        }
    }

    return 0;
}
