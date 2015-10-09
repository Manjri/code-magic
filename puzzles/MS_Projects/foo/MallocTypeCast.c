#include <stdio.h>
#include <stdlib.h>

void WriteToBuffer(unsigned int buf)
{
     //*(unsigned int*)buf = 0xDEADBEEF;    // necessary to typecast to pointer type if we want to modify buf addr
    buf = 0xDEADBEEF;                       // wrong - we are not maninpulating the buf address, just the local var
}


int main()
{
    int status = 0;
    unsigned int buf;
 
    buf = (unsigned int)malloc(1000);
  
    //*(unsigned int*)buf = 0xC0DEC0DE;     // this needs typecasting if we desire to modify buf

    WriteToBuffer(buf);

    free((void*)buf);

    return status;
}