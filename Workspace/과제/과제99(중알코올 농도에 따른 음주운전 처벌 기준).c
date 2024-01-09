#include <stdio.h>

int main()
{
    double ml,f,p,r;
    scanf("%lf %lf %lf %d", &ml, &f, &p, &r);
    if (r==1)
        r=0.7;
    else
        r=0.6;
    double c =  ((ml*(f/100)*0.7984) / (p * r)) / 10;

    printf("%lf\n", c);

    double h;
    int m;
    scanf("%lf %d", &h, &m);
    h+=(double)m/60;
    double ct = c - (0.015*h);

    printf("%.3lf", ct+0.0005);

    return 0;
}
