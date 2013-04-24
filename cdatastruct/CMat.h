#ifndef CMAT_H_INCLUDED
#define CMAT_H_INCLUDED


#include "CCommon.h"

typedef struct CMat_t CMat;
struct CMat_t {
    double * data;

    int row;
    int col;
};

CMat *CMatCreate(int row,int col);
void CMatRelease(CMat * l);

///

void testMat();

#endif // CMAT_H_INCLUDED
