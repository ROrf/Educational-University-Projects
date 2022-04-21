#include<stdio.h>

int main(void)
{
    int x = 0;
    while(x<1)
    {
        printf("Enter a number greater than 0\n");
        scanf("%d", &x);
    }
}
