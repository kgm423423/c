#include <stdio.h>

int main()
{
   int i;
   char arr[20],arr1[20],arr2[20];

   scanf("%s",arr);
   for(i=0;arr[i]!='\0';i++) {
        arr1[i] = arr[i]+2;
        printf("%c",arr1[i]);

   }
   printf("\n");

   for(i=0;arr[i]!='\0';i++) {
        arr2[i] = ((arr[i]*7) % 80) +48;
        printf("%c",arr2[i]);

   }

    return 0;
}
