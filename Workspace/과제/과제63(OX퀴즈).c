#include <stdio.h>

int f(char str[])
{
    int sum=0;

    for(int i=0, j=1;str[i]!='\0';i++,j++) {
        if (str[i]=='O')
            sum+=j;
        else
            j=0;
    }

    return sum;
}

int main()
{
    int n;
    char str[81];

    scanf("%d", &n);

    int arr[n];

    for(int i=0;i<n;i++) {
        scanf("%s", str);
        arr[i]=f(str);
    }

    for(int i=0;i<n;i++)
        printf("%d\n", arr[i]);

    return 0;
}
