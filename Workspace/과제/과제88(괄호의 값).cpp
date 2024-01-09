#include <bits/stdc++.h>

using namespace std;

stack<int> s;

void f(int arr[], int i)
{
    if (arr[i]==0)
                arr[i-1]+=s.top();
    else {
        arr[i-1]+=s.top()*arr[i];
        arr[i]=0;
    }
    s.pop();
    return;
}

int main()
{
    int d=1;
    int i=1;
    char k='\0';
    int arr[31]={};

    while (k!='\n') {
        scanf("%c", &k);

        if (k=='(') {
                s.push(2);
                i++;
            }
        else if (k=='[') {
            s.push(3);
            i++;
        }
        else if (k==')'){
            if (s.empty() || s.top()!=2) {
                d=0;
                break;
            }
            f(arr,i);
            i--;
        }
        else if (k==']'){
            if (s.empty() || s.top()!=3) {
                d=0;
                break;
            }
            f(arr,i);
            i--;
        }
    }

    if (d==1 && s.empty())
        printf("%d", arr[i]);
    else
        printf("0");

    return 0;
}
