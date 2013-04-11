#ifndef CINTMAP_H_INCLUDED
#define CINTMAP_H_INCLUDED

#include "CCommon.h"

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

void testIntMapMain();
#endif // CINTMAP_H_INCLUDED
