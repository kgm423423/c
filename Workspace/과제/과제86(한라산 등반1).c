#include <stdio.h>

int f(int n)
{
    n+=2100;

    if (((n%4==0) && (n%100!=0)) || (n%400==0))
        return 1;
    else
        return 0;
}

int lcm(int n1, int n2)
{
    int n,i=1;

    while (n1>=i && n2>=i) {
        if (n1%i==0 && n2%i==0)
            n=i;
        i++;
    }

    return (n1*n2)/n;
}

int main()
{
    int i=0;
    int n1,n2,n3;
    int n,p;
    int k=0;

    scanf("%d %d %d", &n1, &n2, &n3);


    n=lcm(n1, lcm(n2, n3));
    p=n;
    i=0;

    while(n>=334) {
        k=f(i);

        if (k==1 && n==334)
            break;
        else if (k==1)
            n-=335;
        else
            n-=334;

        i++;
    }

    printf("%d-", 2100+i);

    if (n<=31) {
        printf("01-");
    }
    else if (n<=59+k) {
        printf("02-");
        n-=31;
    }
    else if (n<=90+k) {
        printf("03-");
        n-=59+k;
    }
    else if (n<=120+k) {
        printf("04-");
        n-=90+k;
    }
    else if (n<=151+k) {
        printf("05-");
        n-=120+k;
    }
    else if (n<=181+k) {
        printf("06-");
        n-=151+k;
    }
    else if (n<=212+k) {
        printf("07-");
        n-=181+k;
    }
    else if (n<=243+k) {
        printf("08-");
        n-=212+k;
    }
    else if (n<=273+k) {
        printf("09-");
        n-=243+k;
    }
    else if (n<=304+k) {
        printf("10-");
        n-=273+k;
    }
    else if (n<=334+k) {
        printf("11-");
        n-=304+k;
    }

    if (n<10)
        printf("0%d ", n+1);
    else
        printf("%d ", n+1);

    p=p%7;
    if (p==3)
        printf("MON");
    else if(p==4)
        printf("TUE");
    else if(p==5)
        printf("WED");
    else if(p==6)
        printf("THU");
    else if(p==0)
        printf("FRI");
    else if(p==1)
        printf("SAT");
    else if(p==2)
        printf("SUN");

    return 0;
}
