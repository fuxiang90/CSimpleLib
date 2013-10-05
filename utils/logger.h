#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED


#include "CCommon.h"
#ifdef __cplusplus
extern "C" {
#endif


/*设置路径 */
int logger_init(char * path) ;
/*现在log 只支持单进程 ，如需要复杂的可以用zlog */
int logInfo(char* filename, int line, char *fmt,...);



#ifdef __cplusplus
}
#endif
#endif // LOGGER_H_INCLUDED
