#include <stdio.h>

int main()
{
    int r;

    scanf("%d", &r);

    if (r>=1 && r<74) {
        printf("%d ", r);
        printf("blue ");
        printf("recommend");

    }
    else if (r>=74 && r<100) {
        printf("%d ", r);
        printf("green ");
        printf("possible");

    }
    else if (r>=100 && r<148) {
        printf("%d ", r);
        printf("yellow ");
        printf("careful");

    }
    else if (r>=148 && r<=1000) {
        printf("%d ", r);
        printf("red ");
        printf("stop");

    }
    else {
        printf("%d ", r);
        printf("data error");
    }

    return 0;
}
