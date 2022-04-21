#include<stdio.h>

int main(void)
{
   char test[] = "123456";
   int x[6];
   printf("%d", (int)sizeof(test));
   for(int i = 0; i < sizeof(test); i++)
    {
        x[i] = test[i] - 48;
    }
    printf("%d", x[5]);
}
