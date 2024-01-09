#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,random,arr[10] = {};

    srand(time(NULL));
    for(i=0;i<10;i++) {
        random = rand() % 10;
        arr[random]++;
    }

    for(i=0;i<10;i++) {
        printf("%d ",arr[i]);
    }

     return 0;
}
