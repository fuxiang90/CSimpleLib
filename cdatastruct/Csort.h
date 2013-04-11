#ifndef CSORT_H_INCLUDED
#define CSORT_H_INCLUDED

#include "CCommon.h"



void CQsort(void * data ,int data_size ,int s ,int e ,CompareDataFunc func,SwapDataFunc swapfunc);

void testSortMain();

#endif // CSORT_H_INCLUDED
