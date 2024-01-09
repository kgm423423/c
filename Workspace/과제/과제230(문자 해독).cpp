#include <stdio.h>      //fin
#include <queue>

using namespace std;

int sum = 0;
int w,s;

int sumArr[123] = {};
int wordArr[123] = {};

void f()
{
    for(int i=0;i<123;i++) {
        if (sumArr[i] != wordArr[i]) {
            return;
        }
    }

    sum++;

    return;
}


int main()
{
    scanf("%d %d", &w, &s);
    queue<char> q;

    //정답 배열 입력
    for(int i=0;i<w;i++) {
        char k;
        scanf(" %c", &k);
        sumArr[k]++;
    }

    //초기 값 입력
    for(int i=0;i<w;i++) {
        char k;
        scanf(" %c", &k);
        wordArr[k]++;
        q.push(k);
    }

    f();

    //문자열  입력받기
    for(int i=w;i<s;i++) {
        wordArr[q.front()]--;
        q.pop();
        char k;
        scanf(" %c", &k);
        wordArr[k]++;
        q.push(k);
        f();
    }

    printf("%d", sum);

    return 0;
}
