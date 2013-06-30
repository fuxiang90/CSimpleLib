#ifndef CARRAY_H_INCLUDED
#define CARRAY_H_INCLUDED

#include "CCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MIN_ARRAY_SIZE 16
typedef struct CIntArray_t CIntArray;
struct CIntArray_t {
    int* data;
    unsigned int len ;
};




/*
做一个动态的数组
*/
struct CArray_t {
    void * data; //
    unsigned int len ;//当前的大小
    unsigned int cap ;//当前容量
    unsigned int data_size ;//data 里面内容所占内存的大小
    void (*free)(void *ptr);
};
typedef struct CArray_t CArray;

#define CArrayLength(a) ((a)->len)
#define CArrayCap(a) ((a)->cap)
#define CArraySetFreeMethod(a,m) ((a)->free = (m))

CIntArray *CIntArrayCreate(int len);
void CIntArrayRelease(CIntArray * node);

////////

CArray* CArrayCreate(int cap ,int data_size  );

void CArrayRelease(CArray * array_ptr);

/*在当前len 后面插入一个*/
int CArrayPush(CArray * array_ptr , void * value);

/*清除里面的内容，但是内存的大小并不改变 */
void CArrayClear(CArray * array_ptr);






/*test*/

void CArrayTest();

#ifdef __cplusplus
}
#endif

#endif // CARRAY_H_INCLUDED
