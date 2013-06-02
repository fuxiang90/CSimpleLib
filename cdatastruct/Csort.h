#ifndef CSORT_H_INCLUDED
#define CSORT_H_INCLUDED

#include "CCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

void CQsort(void * data ,int data_size ,int s ,int e ,CompareDataFunc func,SwapDataFunc swapfunc);

void testSortMain();
#ifdef __cplusplus
}
#endif
#endif // CSORT_H_INCLUDED
