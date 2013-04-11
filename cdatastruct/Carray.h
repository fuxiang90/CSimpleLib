#ifndef CARRAY_H_INCLUDED
#define CARRAY_H_INCLUDED

#include "CCommon.h"


typedef struct CIntArray_t CIntArray;
struct CIntArray_t {
    int* data;
    unsigned int len ;
};

typedef struct CArray_t CArray;

struct CArray_t {
    void * data; //int *
    unsigned int len ;
};

//int * dta =mallco

CIntArray *CIntArrayCreate(int len);
void CIntArrayRelease(CIntArray * node);




/**/

CArray * CArrayCreate(int len ,MallocDataFunc  func);
void CArrayRelease( CArray * node );





#endif // CARRAY_H_INCLUDED
