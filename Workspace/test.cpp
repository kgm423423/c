#include <stdio.h>
#include <windows.h>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

const int mapSize = 20;
const int mazeSize = (mapSize*2)+1;
int mapArr[mazeSize][mazeSize] = {};

bool checkArr[mapSize][mapSize];

bool f(int i, int j)
{
    if (i < 0 || i >= mapSize || j < 0 || j >= mapSize)
        return false;
    if (checkArr[i][j] == true)
        return false;

    checkArr[i][j] = true;

    ///¼ø¼­ µÚ¼¯±â
    int order[4] = {1,2,3,4};
    for(int inex=0;inex<4;inex++) {
        int n1 = rand() % 4;
        int n2 = rand() % 4;
        int x = n1;
        n1 = n2;
        n2 = x;
    }

    int ii = (i*2)+1;
    int jj = (j*2)+1;

    for(int inex=0;inex<4;inex++) {
        switch(order[inex]){
        case 1:
            mapArr[ii+1][jj] = f(i+1, j) ? 1 : 0;
            break;
        case 2:
            mapArr[ii][jj+1] = f(i, j+1) ? 1 : 0;
            break;
        case 3:
            mapArr[ii-1][jj] = f(i-1, j) ? 1 : 0;
            break;
        case 4:
            mapArr[ii][jj-1] = f(i, j-1) ? 1 : 0;
            break;
        }
    }

    return true;
}

int main() {
    srand((unsigned int)time(NULL));

    for(int i=0;i<mapSize;i++)
        for(int j=0;j<mapSize;j++) {
            checkArr[i][j] = false;
        }
    for(int i=1;i<mazeSize;i+=2)
        for(int j=1;j<mazeSize;j+=2) {
            mapArr[i][j] = 1;
        }

    f(1,1);

    for(int i=0;i<mazeSize;i++) {
        for(int j=0;j<mazeSize;j++) {
            if (mapArr[i][j] == 0) {
                printf("0");
            }
            else
                printf(" ");
        }
        printf("\n");
    }



    return 0;
}
