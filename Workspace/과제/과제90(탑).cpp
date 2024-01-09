#include <stdio.h>
#include <stack>

using namespace std;

stack<int> s;

int main()
{
    int n;
    int i,j;
    scanf("%d", &n);
    int arr[n+1];
    arr[0]=100000001;

    for(i=1;i<=n;i++)
        scanf("%d", &arr[i]);

    for(i=n;i>0;i--)
        for(j=i-1;j>=0;j--)
            if (arr[i]<arr[j]) {
                s.push(j);
                break;
            }

    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}
