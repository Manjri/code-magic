#include <stdio.h>

/**
   Macro used to define a command ID based on the service ID and
   function number.
*/
#define TZ_SYSCALL_CREATE_CMD_ID(s, f) \
  ((int)(((s & 0x3ff) << 10) | (f & 0x3ff)))

#define tzt_fastcall_tz3(xxid) \
  ((int)((xxid << 12) |  3))

int createSysCall()
{
       int s = 0x1;
       int f = 0xb;
       int test_s = 255;
       int test_f = 1;

       printf("\nSysCall with test_s = %x, test_f= %x := %x",s,f,(TZ_SYSCALL_CREATE_CMD_ID(s,f)));    

       printf("\nSysCall with test_s = %x, test_f= %x := %x",test_s,test_f,(TZ_SYSCALL_CREATE_CMD_ID(test_s,test_f)));

       printf("\nFastCall: %x", tzt_fastcall_tz3((TZ_SYSCALL_CREATE_CMD_ID(test_s,test_f))));

       return 0;
}
