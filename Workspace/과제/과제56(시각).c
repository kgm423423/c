#include <stdio.h>

_Bool f(int t)
{
    if (t/10 == 3)
        return 1;
    if (t-((t/10)*10)==3)
        return 1;

    return 0;
}

int main()
{
    int s,m,h,sum=0;

    scanf("%d", &h);

    for(int i=0;i<=h;i++) {
        if (f(i)==1) {
            sum+=3600;
            printf("%2d:%2d:%2d  %d\n", i, m, s, sum);
            continue;
        }

        for(m=0;m<60;m++) {
            if (f(m)==1) {
                sum+=60;
                printf("%2d:%2d:%2d  %d\n", i, m, s, sum);
                continue;
            }

            for(s=0;s<60;s++) {
                if (f(s)==1) {
                    sum++;
                    printf("%2d:%2d:%2d  %d\n", i, m, s, sum);
                }
            }

        }

    }

    printf("%d", sum);

    return 0;
}
