#include <iostream>
#include <stdint.h>

uint32_t  *memCpySrc;
uint32_t  *memCpyDst; 

#define FAST_MEM_COPY(Count,Src,Dst)    \
do{     \
    switch(Count&3) \
    {	              \
        case 3:  *Dst++=*Src++; \
        case 2:  *Dst++=*Src++; \
        case 1:  *Dst++=*Src++; \
        case 0: {	              \
                    int count = Count>>2;	\
                    int times	= ((count+7)>>3);	\
                    if(times)	                  \
                    {	                          \
                        memCpySrc = (uint32_t  *)Src;	\
                        memCpyDst = (uint32_t  *)Dst;	\
                        switch( count & 7 )	\
                        {	\
                            case 0:	\
                                    do \
                                    {	\
                                        *memCpyDst++=*memCpySrc++;	\
                                        case 7: *memCpyDst++=*memCpySrc++;	\
                                        case 6: *memCpyDst++=*memCpySrc++;	\
                                        case 5: *memCpyDst++=*memCpySrc++;	\
                                        case 4: *memCpyDst++=*memCpySrc++;	\
                                        case 3: *memCpyDst++=*memCpySrc++;	\
                                        case 2: *memCpyDst++=*memCpySrc++;	\
                                        case 1: *memCpyDst++=*memCpySrc++;	\
                                    }while(--times > 0);	\
                        }	\
                        Src = (uint8_t *) memCpySrc;	\
                        Dst = (uint8_t *) memCpyDst;	\
                    }	\
        }	\
     }	\
} while( 0 )


int main()
{
    uint8_t a[4] = {1,2,3,4};
    uint8_t b[4] = {0};

    FAST_MEM_COPY(4,a,b);
}