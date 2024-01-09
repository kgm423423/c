#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;

int main()
{
    string a;
    scanf("%s", &a);
    printf("aaaa\n");
    v.push_back(a);
    printf("bbbb\n");
    printf("%d", v.size());

    return 0;
}
