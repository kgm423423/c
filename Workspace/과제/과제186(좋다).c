#include <stdio.h>      //fin

int n,m;

void quickSort(int arr[], int s, int e)
{
    if (s>=e)
        return;

    int i=s+1,j=e;

    while(i<=j) {
        while(i<=e && arr[s]>=arr[i])
            i++;
        while(j>s && arr[s]<=arr[j])
            j--;

        if (i<j) {
            int k = arr[i];
            arr[i] = arr[j];
            arr[j] = k;
        }
    }

    int k = arr[s];
    arr[s] = arr[j];
    arr[j] = k;

    quickSort(arr,s,j-1);
    quickSort(arr,j+1,e);

    return;
}

int twoPointer(int arr[], int t)
{
    int i,j;
    int addN;
    i=0;j=n-1;

    while (i<j) {
z
        addN = arr[i] + arr[j];

        if (i == t)
            i++;
        else if (j == t)
            j--;
        else if (addN == arr[t]) {
            return 1;
        }
        else
            addN < arr[t] ? i++ : j--;
    }

    return 0;
}

int main()
{
    int i,j,k;
    int sum = 0;

    scanf("%d", &n);

    int arr[n];


    //배열 입력받기
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }



    //정렬
    quickSort(arr,0,n-1);



    //계산
    i = 0;
    for(k=0;k<n;k++) {
        if (twoPointer(arr, k) == 1)
            sum++;
    }

    printf("%d", sum);

    return 0;
}
