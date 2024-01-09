#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;    //8:40

int minN = 0;
int maxN = 0;

//재귀함수 생성
void f(queue<int> arr,int opt[],int sum)
{
    while(!arr.empty()) {
        if (opt[1] != 0) {

        }
    }



    return;
}


int main()
{
    //값 입력받기
    int i,j;
    int n;
    scanf("%d",&n);
    queue<int> arr;
    queue<int> arr2;
    int opt[n];

    for(i=0;i<n;i++) {
        scanf("%d", &j);
        arr.push(j);
        arr2.push(j);
    }

    for(i=0;i<4;i++)
        scanf("%d",&opt[i]);

    arr2.pop();

    //함수 열기
    for(i=0;i<n;i++) {
         f(arr2,opt,arr.front());
         arr.pop();
    }




    //값 출력













    return 0;
}
