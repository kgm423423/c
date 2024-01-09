#include <stdio.h>

int BinarySearch(int arr[], int t, int s, int e, bool k)
{
    if (s == e) {
        return s;
    }

    int m = (s+e)/2;

    printf("%d %d %d \n m : %d %d\n\n", s, e, t, m, arr[m]);


    if (arr[m] == t) {
        if (k)
            return BinarySearch(arr, t, m+1, e, k);
        else
            return BinarySearch(arr, t, s, m, k);
    }
    else if (arr[m] < t)
        return BinarySearch(arr, t, m+1, e, k);
    else if (arr[m] > t)
        return BinarySearch(arr, t, s, m, k);

    return 0;
}

int main()
{
    int i,j;
    int n,m,p;

    scanf("%d", &n);

    int arr[n];

    /// #1 배열 입력
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    // 배열 정렬
    for(i=n-1;i>0;i--)
        for(j=0;j<i;j++)
            if (arr[j] > arr[j+1]) {
                int k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }



    /// #2 갯수 배열 입력
    scanf("%d", &m);

    int num[m];

    for(i=0;i<m;i++)
        scanf("%d", &num[i]);

    // 배열 정렬
    for(i=n-1;i>0;i--)
        for(j=0;j<i;j++)
            if (num[j] > num[j+1]) {
                int k = num[j];
                num[j] = num[j+1];
                num[j+1] = k;
            }



    /// #3 갯수 출력
    int s = 0; int e;
    for(i=0;i < m;i++) {
        s = BinarySearch(arr, num[i], s, n-1, false);
        e = BinarySearch(arr, num[i], s, n-1, true);

        if (arr[num[i]] == arr[s] && arr[num[i]] == arr[e])
            printf("%d\n", e-s+1);
        else if (s == 0 || e == 0)
            printf("0\n");
        else if (arr[num[i]] != arr[s]) {
            s--;
            printf("%d\n", e-s+1);
        }
        else {
            s++;
            printf("%d\n", e-s+1);
        }

        s = e;
    }



    return 0;
}
