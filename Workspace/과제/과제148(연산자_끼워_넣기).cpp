#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;    //8:40      Permutation 순열 알고리즘

int n;
int minN = 2000000000;
int maxN = -2000000000;

int opt[4];

//연산함수 생성
void f2(int arr[],int opt[], int sum, int p)
{
    int i,j;

    if (p == n) {
        if (sum > maxN)
            maxN = sum;
        else if (sum < minN)
            minN = sum;
    }
    else {
        if (opt[0] != 0) {
            int opt2[4] = {opt[0],opt[1],opt[2],opt[3]};
            opt2[0]--;
            f2(arr,opt2,sum+arr[p],p+1);
        }
        if (opt[1] != 0) {
            int opt2[4] = {opt[0],opt[1],opt[2],opt[3]};
            opt2[1]--;
            f2(arr,opt2,sum-arr[p],p+1);
        }
        if (opt[2] != 0) {
            int opt2[4] = {opt[0],opt[1],opt[2],opt[3]};
            opt2[2]--;
            f2(arr,opt2,sum*arr[p],p+1);
        }
        if (opt[3] != 0) {
            int opt2[4] = {opt[0],opt[1],opt[2],opt[3]};
            opt2[3]--;
            f2(arr,opt2,sum/arr[p],p+1);
        }
    }

    return;
}

//순열함수 생성
void f(int arr[], int p)
{
    int i,j;

    if (p == n-1) {
        f2(arr,opt,arr[0],1);
    }
    else {

        for(i=p;i<n;i++) {
            int arr2[n-1];

            for(j=0;j<n;j++)
                arr2[j] = arr[j];

            int k = arr2[p];
            arr2[p] = arr2[i];
            arr2[i] = k;

            f(arr2,p+1);
        }
    }

    return;
}

int main()
{
    //값 입력받기
    int i,j;
    scanf("%d", &n);
    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    scanf("%d %d %d %d",&opt[0],&opt[1],&opt[2],&opt[3]);

    //함수 열기
    f(arr,0);

    //값 출력
    printf("%d\n%d",maxN, minN);

    return 0;
}
