#include <stdio.h>

int main()
{
    int i,j,k;
    char arr[100],n;

    scanf("%s",&arr);
    for(i=0;arr[i]!='\0';i++)
    k = i;
    for(i--,j=0;j<=k/2;i--,j++) {
        n = arr[i];
        arr[i] = arr[j];
        arr[j] = n;
    }
    printf("%s",arr);

    return 0;
}
