#include <stdio.h>
#include <stdlib.h>

#define E_SUCCESS 0
#define E_FAILURE_1 1
#define E_FAILURE_2 -1

int func_success()
{
    return E_SUCCESS;
}

int func_failure1()
{
    return E_FAILURE_1;
}

int func_failure2()
{
    return E_FAILURE_2;
}

int main()
{
    if(func_success())
        printf("\n Failed func_success\n");

    if(func_failure1())
        printf("\n Failed func_failure1\n");

    if(func_failure2())
        printf("\n Failed func_failure2\n");

    return 0;
}
