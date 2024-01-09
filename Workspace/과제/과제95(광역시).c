#include <stdio.h>
#include <math.h>

int n;

struct node
{
    double d;
    int p;
};

double distance(int n1, int n2)
{
    return sqrt(pow(n1,2)+pow(n2,2));
}

double f(struct node arr[], int p, double s, double e)
{
    int i;
    int sum=0;
    double k = (s+e)/2;

    if (s>e)
        return k;

    for(i=0;i<n;i++) {
        if (arr[i].d <= k)
            sum+=arr[i].p;
    }

    sum+=p;

    if (sum>=1000000)
        return f(arr, p, s, k-0.0005);
    else if (sum<1000000)
        return f(arr, p, k+0.0005, e);
}

int main()
{
    int i;
    int n1,n2,n3,p;
    double k=0;

    scanf("%d %d", &n, &p);
    struct node arr[n];         //선언

    for(i=0;i<n;i++) {
        scanf("%d %d %d", &n1, &n2, &n3);
        arr[i].d = distance(n1, n2);
        arr[i].p = n3;
        if (arr[i].d > k)
            k=arr[i].d;         //입력
    }

    printf("%.3lf", f(arr, p, sqrt(2), k));       //출력

    return 0;
}
