#include <stdio.h>
#include <stdarg.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(const char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    const char *p, *sval;
    int ival;
    double dval;
    
    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    
    for (p = fmt; *p; p++) {         /* [1] */
        if (*p != '%') {
            putchar(*p);
            continue;                /* [2] */
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}
/* Driver program to test above functions*/
int main()
{
    minprintf("Hello %d times\n", 2);
    return 0;
}
