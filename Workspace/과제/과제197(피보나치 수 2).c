#include <stdio.h>      //fin
#define length 21

int n;
int sum[length] = {};

void f(int n1[], int n2[], int i)
{
    int ii;

    if (i > n) {
        for(ii=length-1;ii>=0;ii--)
            sum[ii] = n2[ii];
        return;
    }

    int n3[length] = {};

    for(ii=length-1;ii>1;ii--) {
        n3[ii] += n1[ii]+ n2[ii];
        if(n3[ii] > 9) {
            n3[ii-1] += n3[ii] / 10 ;
            n3[ii] = n3[ii] % 10;
        }
    }

    return f(n2,n3,i+1);
}


int main()
{
    int ii;

    int n1[length] = {};
    int n2[length] = {};

    n2[length-1] = 1;

    scanf("%d", &n);

    if (n==0)
        printf("0");
    else
        f(n1,n2,2);


    for(ii=0;ii<length;ii++)
        if (sum[ii] != 0)
            break;

    for(;ii<length;ii++)
        printf("%d",sum[ii]);

    return 0;
}
