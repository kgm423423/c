#include <iostream>     //fin
#include <vector>

using namespace std;

int main()
{
    int i;
    char k;
    int n;
    scanf("%d", &n);
    vector<char> arr;
    int sum=0;

    getchar();

    for(i=0;i<n;i++) {
        scanf("%c", &k);
        arr.push_back(k);
    }

    for(i=0;i<n;i++)
        sum += (arr[i]-48);

    printf("%d", sum);

    return 0;
}
