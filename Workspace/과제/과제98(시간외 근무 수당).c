#include <stdio.h>  //fin

int main()
{
    int i;
    double s,e,k;
    double t=0;

    for(i=0;i<5;i++) {
        scanf("%lf %lf", &s, &e);
        k=e-s;

        if (k>1)
            if (k>5)
                t+=4;
            else
                t+=k-1;
    }

    if (t>=15)
        t*=0.95;
    else if (t<=5)
        t*=1.05;

    printf("%.0lf", t*10000);

    return 0;
}
