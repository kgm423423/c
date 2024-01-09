#include <stdio.h>

void printArr(int arr[], int s, int e)
{
    for(;s<=e;s++)
        printf("%d ", arr[s]);

    printf("\n\n");

    return;
}

void f(int arr[], int s, int e)
{
    if (s>=e)
        return;

    int i=s+1,j=e;

    printf("A %d %d\n\n\n",s,e);

    while(i<=j) {
        while(i<=e && arr[s]>=arr[i])
            i++;
        while(j>s && arr[s]<=arr[j])
            j--;

        printf("B %d %d\n",i,j);
        if (i<j) {
            int k = arr[i];
            arr[i] = arr[j];
            arr[j] = k;
        }
    }

    printf("C %d %d\n",s,j);
    int k = arr[s];
    arr[s] = arr[j];
    arr[j] = k;
    printArr(arr,s,e);

    f(arr,s,j-1);
    f(arr,j+1,e);

    return;
}

int main()
{
    int i,j;
    int n;

    scanf("%d", &n);
    int arr[n];



    //배열 입력
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    //퀵정렬
    f(arr,0,n-1);



    //배열출력
    for(i=0;i<n;i++)
        printf("%d\n", arr[i]);


    return 0;
}
