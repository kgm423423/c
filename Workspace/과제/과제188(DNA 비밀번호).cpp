#include <stdio.h>      //fin
#include <queue>

using namespace std;


queue<char> q;

int dnaIndex(char k)
{
    if (k == 'A')
        return 0;
    if (k == 'C')
        return 1;
    if (k == 'G')
        return 2;
    if (k == 'T')
        return 3;

    return -1;
}

bool dnaCheck(int arr[], int myArr[])
{
    int i;

    for(i=0;i<4;i++)
        if (myArr[i] < arr[i])
            return false;

    return true;
}

int main()
{
    int i;
    char k;
    int n,m;
    int sum = 0;
    int dnaArr[4] = {};
    int myDnaArr[4] = {};

    scanf("%d %d", &n, &m);

    char arr[n];



    //배열 입력받기
    getchar();
    for(i=0;i<n;i++)
        scanf("%c", &arr[i]);

    for(i=0;i<4;i++)
        scanf("%d", &dnaArr[i]);


    //기본값 입력
    for(i=0;i<m;i++) {
        q.push(arr[i]);
        myDnaArr[dnaIndex(arr[i])]++;
    }


    if (dnaCheck(dnaArr, myDnaArr))
            sum++;


    //계산
    while (i<n) {
        q.push(arr[i]);
        myDnaArr[dnaIndex(arr[i])]++;

        myDnaArr[dnaIndex(q.front())]--;
        q.pop();

        if (dnaCheck(dnaArr, myDnaArr))
            sum++;

        i++;
    }

    printf("%d", sum);

    return 0;
}
