#include <stdio.h>

int Add(int a, int b) //o o
{
    int c = a + b;

    return c;
}

int sc() //o x
{
    int b;

    scanf("%d",&b);

    return b;
}

void pr(int a) //x o
{
    printf("%d",a);

}

void start() //x x
{
    printf("이 프로그램은 두 수를 더하는 프로그램입니다 두 숫자를 입력해주세요 : ");
}

int  main()
{
    int a,b;

    start();

    a = sc();
    b = sc();

    pr(Add(a ,b));

    return 0;
}
