#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;

double n = 1;

void func1() {
    int i = 1;
    while (true) {
        printf("1:%d / %f %f\n", i, i/n*100, n);
        i++; n++;
    }
}

void func2() {
    int i = 1;
    while (true) {
        printf("2:%d / %f %f\n", i, i/n*100, n);
        i++; n++;
    }
}

int main() {
  thread t1(func1);
  thread t2(func2);

  t1.join();
  t2.join();

  return 0;
}
