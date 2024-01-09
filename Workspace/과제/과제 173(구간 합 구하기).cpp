#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j;
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    int arr[n+1];
    arr[0]=0;

    for(i=1;i<=n;i++) {
        scanf("%d", &j);
        arr[i] = arr[i-1]+j;
    }

    m+=k;
    for(i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);

        if (a==1) {
            c -= arr[b];
            for(j=b;b<=n;b++)
                arr[b] += c;
        }
        else if (a==2) {
            if (b==c)
                printf("%d\n",arr[b]);
            else
                printf("%d", (arr[c]-arr[b]));
        }
    }

    return 0;
}
