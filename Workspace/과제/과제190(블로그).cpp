#include <stdio.h>      //fin
#include <queue>

using namespace std;


int main()
{
    int i;
    int n,m;
    int sum = 0;
    int maxSum;
    int sumCount = 1;

    queue<int> q;

    scanf("%d %d", &n, &m);


    //배열 입력받기
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);


    //기본값 입력
    for(i=0;i<m;i++) {
        q.push(arr[i]);
        sum += arr[i];
    }

    maxSum = sum;


    //계산
    while(i<n) {
        sum += arr[i];
        q.push(arr[i]);
        sum -= q.front();
        q.pop();


        if (sum > maxSum) {
           maxSum = sum;
           sumCount = 1;
        }
        else if (sum == maxSum)
            sumCount++;

        i++;
    }


    //답 출력
    if (maxSum == 0)
        printf("SAD");
    else
        printf("%d\n%d",maxSum, sumCount);

    return 0;
}
