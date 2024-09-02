#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <thread>
#include <chrono>
#include <windows.h>

using  namespace std;

const double PI = 3.14159265359;


int length = 50;
int speed = 5;

void beepF()
{
    Beep(speed*100, 200);

    Yield();
}

void printFunc(double r)
{
    int x = (r*length) + length;

    for(int i=0;i<length*2;i++) {
        if (i == x)
            printf("бс");
        else
            printf("  ");

    }

    //printf("\n");

    return;
}

void drawGraph()
{
    unsigned int n;
    double sinN;
    double sinN2 = 1;

    while (1) {
        double r = n*PI/180;
         sinN = sin(r);


        printFunc(sinN);
        printf("\n");

        if ((sinN >= 0 && sinN2 <= 0) ||
            (sinN <= 0 && sinN2 >= 0))
            thread _t2(beepF);





        //getch();
        //system("cls");
        n += speed;
        sinN2 = sinN;
    }
}

void test()
{
    unsigned int n;
    double sinN2 = 1;

    while (1) {
        double r = n*PI/180;
        double sinN = sin(r);


        printf("%f %f", sinN, sinN2);
        printf("\n");

        if ((sinN >= 0 && sinN2 <= 0) ||
            (sinN <= 0 && sinN2 >= 0))
            Beep(speed*100, 200);

        sinN2 = sinN;
        n += speed;
    }
}

int main()
{
    thread _t1(drawGraph);
    //thread _t1(test);

    int c;
    while (1){
        this_thread::sleep_for(chrono::milliseconds(1));
        if (_kbhit()) {
            c = _getch();
            if (c == 224) {
                c = _getch();
                if (c == 80 && speed > 1)
                    speed--;
                else if (c == 72 && speed < 10)
                    speed++;
                else if (c == 75 && length > 10)
                    length -= 10;
                else if (c == 77 && length < 100)
                    length += 10;

                Beep(speed*100, 200);
            }
        }
    }

    return 0;
}
