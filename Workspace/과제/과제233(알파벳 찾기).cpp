#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int i;
    char k = '\0';
    char input[101];
    int sum[27];
    bool check[27];



    //�迭 �ʱ�ȭ
    for(i=0;i<26;i++) {
        sum[i] = 0;
        check[i] = 0;
    }


    // ���ڿ� �Է¹ޱ�
    i=0;
    while (k!='\n') {
        scanf("%c", &k);
        if (!check[(k-97)]) {
            sum[(k-97)] = i;
            check[(k-97)] = 1;
        }
        i++;
    }


    //�� ���
    for(int i=0;i<26;i++) {
        if (check[i]) {printf("%d ", sum[i]); }
        else          {printf("-1 "); }
    }




    return 0;
}

