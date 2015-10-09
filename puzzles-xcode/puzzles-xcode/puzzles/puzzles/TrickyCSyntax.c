#include <stdio.h>
#include <stdlib.h>

#define PRINT_ERROR_AND_FINISH() \
                                  printf("function failed\n"); \
                                  goto done;
 
#define STATUS_SUCCESS 0
#define STATUS_FAILURE -1

int Function1()
{
    return STATUS_FAILURE;
}

int Function2(unsigned int buf)
{
    return STATUS_SUCCESS;
}

int DoesSomething()
{
    int status;
    unsigned int buf;
    int err;
 
    buf = (unsigned int)malloc(1000);
 
    err = Function1();
 
    if ( err != STATUS_SUCCESS )
        PRINT_ERROR_AND_FINISH();
    else
        status = Function2(buf);
 
    free((void*)buf);
 
done:
    return status;
}


int main()
{
    DoesSomething();
    return 0;
}


#ifdef __POINTERS__

typedef struct
{
   int a[5];
} foo;
 
void main()
{
    printf("%d", ((foo*)0)+5);
}

#endif