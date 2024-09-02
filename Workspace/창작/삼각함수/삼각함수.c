#include <stdio.h>
#include <math.h>
#include <conio.h>

#define _USE_MATH_DEFINES

int length = 100;
int speed = 1;

void printFunc(double r)
{
    int x = (r*length) + length;

    for(int i=0;i<length*2;i++) {
        if (i == x)
            printf("бс");
        else
            printf("бр");

    }

    //printf("\n");

    return;
}

int main()
{
    int n;

    while (1) {
        double r = n*M_PI/180;
        double sinN = sin(r);
        double cosN = cos(r);
        double tanN = tan(r);

        //printf("%d \n%f %f %f\n", n%360, sinN, cosN, tanN);
        printFunc(sinN);
        //printFunc(cosN);
        //printFunc(tanN);
        printf("\n");

        //getch();
        //system("cls");
        n += speed;
    }

    return 0;
}
