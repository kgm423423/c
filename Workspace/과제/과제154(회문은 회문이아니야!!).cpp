#include <stdio.h>      //fin
#include <iostream>

using namespace std;

int arrLen;

bool f(char arr[], int i, int j)
{
    if (i==j)
        return true;

    while (i<j) {
        if (arr[i] != arr[j])
            return false;
        i++; j--;
    }

    return true;
}

int main()
{
    int i,j;
    char k='\0';
    char arr[500000];



    //배열 입력받기
    arrLen=0;
    while (k!='\n') {
        scanf("%c", &k);
        arr[arrLen]=k;
        arrLen++;
    }
    arrLen--;




    //회문 체크
    if (f(arr,0,arrLen-1) == false)
        printf("%d", arrLen);
    else if (f(arr,0,arrLen-2) == false)
        printf("%d", arrLen-1);
    else
        printf("-1");

    return 0;
}
