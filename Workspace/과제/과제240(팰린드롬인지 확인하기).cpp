#include <stdio.h>

int main()
{
    int i = 0;
    char arr[101];
    int arrLen;
    bool sum =1;

    arr[0] = '\0';
    while (arr[i] != '\n') {
        i++;
        scanf("%c", &arr[i]);
    }
    arrLen = i;

    for(int j=1;j<=i/2;j++) {
        if (arr[j] == arr[arrLen-j])
            continue;
        sum = 0;
        break;
    }

    printf("%d", sum);


    return 0;
}
