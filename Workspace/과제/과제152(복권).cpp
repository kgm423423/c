#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<algorithm>

using namespace std;

void mySort(int arr[])
{
    int i,j;
    int arrLen = 7;

    for(i=arrLen-1;i>=0;i--) {
        for(j=0;j<i;j++) {
            if (arr[j] > arr[j+1]) {
                int k =arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }
        }
    }

    return;
}

void randArr(int arr[])
{
    int i=0;
    bool k;
    int arrLen = 7;

    while(i<arrLen) {
        arr[i] = (rand() % 45)+1;

        for(int j=0,k=false;j<i;j++) {
            if (arr[i]==arr[j]) {
                k = true;
                break;
            }
        }
        if (k==true){
            continue;
        }
        else{
            i++;
        }
   }

    return;
}

void plrArrF(int arr[])
{
    int i,j;
    int arrLen = 7;

    printf("번호 입력 : ");
    for(i=0;i<arrLen;i++)
        scanf("%d", &arr[i]);

    for(i=1;i<arrLen;i++) {
        for(j=0;j<i;j++) {
            if (arr[i]==arr[j]) {
                printf("중복값 있음 재입력\n");
                plrArrF(arr);
            }
        }
    }

    return;
}

int main()
{
    srand(time(NULL));
    int i,j;
    int arr[7];
    int plrArr[7];

   randArr(arr);
   //mySort(arr);
   printf("\n");
   sort(arr,arr+7);

   plrArrF(plrArr);
   //mySort(plrArr);
   sort(arr,arr+7);

   for(i=0,j=8;i<6;i++) {
    if (arr[i]==plrArr[i])
        j--;
   }

   if (j==2)
        printf("1등 입니다.");
   else if (j==3 && arr[6]==plrArr[6])
        printf("2등 입니다.");
    else
        printf("%d등 입니다.",j);

    return 0;
}
