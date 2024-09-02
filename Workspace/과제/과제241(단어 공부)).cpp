#include <stdio.h>



int main()
{

    int arr[26] = {};
    char k = '\0';
    int arrLen = 0;
    int sum = 0;
    bool same = false;

    scanf("%c", &k);
    while (k != '\n') {
        arr[k-65]++;
        scanf("%c", &k);
        arrLen++;
    }
    for(int i=0;i<26;i++)
        printf("%d\n", arr[i]);

    for(int i=0;i<26;i++) {
        if (arr[i] > arr[sum]) {
            sum = i;
            same = false;
        }
        else if (arr[i] == arr[sum]) {
            same = true;
        }
        printf("%d %d %d\n", i, arr[i], sum);
    }

    if (same)
        printf("?");
    else
        printf("%c", sum);
    printf("sum : %d", sum);


    return 0;
}
