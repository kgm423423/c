#include <stdio.h>
int main()
{
    int i,s;
    char arr[1000];

    scanf("%s",&arr);
    for(i=0;arr[i]!='\0';i++) {
        s = arr[i];
        if (s>=97 && s<=122)
            s -= 32;
        else if(s>=65)
            s += 32;
        arr[i] = s;
    }
    printf("%s",arr);
    return 0;
}
