#include <iostream>
#include<cstdlib>
#include<ctime>

bool f()
{
    int i;

    int ans;

   bool arr[3];

   //차의 위치를 고름
   arr[0] = true;
   arr[1] = false;
   arr[2] = false;

   //처음 선택
   ans = rand()%3;

   if (arr[ans])
        return true;

    //다시 선택
    ans = rand()%2;

   if (arr[ans])
    return true;
   else
    return false;
}

int main()
{
    int  i,j;
    int sum = 0;
    srand(time(NULL));

    for(i=0;i<1000000;i++)
        if (f())
            sum++;

    printf("%d", sum / 10000);

    return 0;
}
