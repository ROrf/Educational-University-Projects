#include<stdio.h>

typedef struct _test
{
    int intvar;
    enum _num {ONE}Num;
    char * stringvar;
}Test;

void print(Test * pTest)
{
    printf("%d %s\n", pTest->intvar, pTest->stringvar);
    if(pTest->Num == ONE)
    {
        printf("ONE\n");
    }
}
