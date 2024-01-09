 #include <stdio.h>

int n;

 int f(char* arr, int i, int j)
 {
    if (*(arr+i*n+j)=='0' || i<0 || i>=n || j<0 || j>=n)
        return 0;

    *(arr+i*n+j)='0';

    return f(arr, i+1, j)+f(arr, i, j+1)+f(arr, i, j-1)+f(arr, i-1, j)+1;
 }

 int main()
 {
    int i,j,num=0;

    scanf("%d", &n);
    char arr[n][n];
    int arr2[(n*n+1)/2];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf(" %c", &arr[i][j]);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if (arr[i][j]=='1') {
                arr2[num]=f(arr, i, j);
                num++;
            }

    printf("%d\n", num);

    for(i=0;i<num;i++)
        printf("%d\n",arr2[i]);

    return 0;
 }
