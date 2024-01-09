#include <stdio.h>

int main()
{
    double sum = 0;
    int i=0;
    double j=1;

    while (i < 10000 || i!=0) {
        if (i%2==0)
          sum += 1/j;
        else
            sum -= 1/j;
        j+=2;
        i++;

        printf("%f\n", sum * 4);

    }






}
