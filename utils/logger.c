#include "logger.h"
#include <stdarg.h>


int logInfo(char* filename, int line, char *fmt,...)
{
    int len = 256;
    char * msg = (char *)malloc(sizeof(char)* 256);
    va_list ap;
    while (1) {

        va_start(ap, fmt);
        int n = vsnprintf((char *)msg, len, fmt, ap);
        va_end(ap);
        if (n > -1 && n < len) {
            msg = (char *)realloc(msg,n);
            break;
        }
        if (n > -1)
            len = n + 1;
        else
            len *= 2;
    }

    printf("%s\n",msg);


}
