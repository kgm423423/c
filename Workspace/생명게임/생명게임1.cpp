#include <stdio.h>
#include <list>
#include<stdlib.h>
#include<time.h>

struct cell
{
    ///번호
    int num;

    ///위치정보
    int x;
    int y;

    ///특성
    int speed;
    int life;
    int _size;
};

const int mapSize = 30;
const int respawnDelay = 10;
int mapArr[mapSize][mapSize] = {};
list <struct cell> cells;


void respawn(int delay)
{
    if (delay >= respawnDelay) {
        ///생명 생성
        cells.push_back()


        delay = 0;
    }
    else
        delay++;
}


int main()
{
    srand((unsigned int)time(NULL));
    int delay = 0;

    while (true) {
        respawn(delay);
    }





    return 0;
}
