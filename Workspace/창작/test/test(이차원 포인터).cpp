#include <stdio.h>

int main()
{
    int** arr;
    arr = new int* [3];
    for(int i=0; i<3; i++)
        arr[i] = new int[4];

    arr[2][3] = 0;





    return 0;
}
