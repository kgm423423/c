#include <stdio.h>
#include <stack>

using namespace std;

stack<char> s;

int main()
{
    int i=0;
    int sum=0;
    char arr[100001];

    scanf("%s", arr);
    while(arr[i]!='\0') {
        if (arr[i]=='(' && arr[i+1]==')') {
            sum+=s.size();
            i++;
        }
        else if (arr[i]=='(')
            s.push('(');
        else if (arr[i]==')') {
            s.pop();
            sum++;
        }
        i++;
    }

    printf("%d", sum);

    return 0;
}
