#ifndef CINTMAP_H_INCLUDED
#define CINTMAP_H_INCLUDED

#include "CCommon.h"
#include "Csort.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef   int cint;

typedef struct CIntMapData_t CIntMapData;
struct CIntMapData_t{
    cint key;
    cint value;
};



typedef struct CIntMap_t  CIntMap;
struct CIntMap_t
{
    struct CIntMapData_t * arr;
    int len;
    int now_pos;
};

CIntMap * CIntMapCreate(int len ,MallocDataFunc func);
CIntMap * CIntMapInsert(CIntMap *  map_head,CIntMapData * intmap_node );
CIntMap * CIntMapSort(CIntMap *  map_head, CompareDataFunc func ,SwapDataFunc swapfunc);
CIntMapData * CIntMapFind(CIntMap *  map_head, cint key );
void CIntMapRelease(CIntMap *  map_head );

void testIntMapMain();

#ifdef __cplusplus
}
#endif
#endif // CINTMAP_H_INCLUDED
