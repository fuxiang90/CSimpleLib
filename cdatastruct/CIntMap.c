#include "CIntMap.h"


CIntMap * CIntMapCreate(int len ,MallocDataFunc func)
{

    CIntMap * map_node = (CIntMap * )malloc(sizeof(struct CIntMap_t));
    if(map_node == NULL){
        printf("memory error\n");
        exit(0);
    }
    map_node->arr = func(len);
    map_node->len = len;
    map_node->now_pos = 0;


    return map_node;
}
/*
*依次插入
*/
CIntMap * CIntMapInsert(CIntMap *  map_head,CIntMapData * intmap_node )
{
    if(map_head->now_pos == map_head -> len){
        printf("intmap is full\n");
        return map_head;
    }
    int pos = map_head->now_pos;
    struct CIntMapData_t  *intmap_temp = & (map_head->arr[pos]);

    intmap_temp->key = intmap_node->key;
    intmap_temp->value = intmap_node->value;
    map_head->now_pos ++;

    return map_head;
}

static void * CIntMapDataMalloc(int len)
{
    void * ptr = malloc(sizeof(struct CIntMapData_t)*len);

    if(ptr == NULL){
        printf("memory error\n");
        exit(0);
    }

    return ptr;

}

void testIntMapMain()
{
    CIntMap * head;
    head = CIntMapCreate(10,CIntMapDataMalloc);

    CIntMapData a;
    int i ;
    for(i = 0 ; i < 10 ; i ++){
        a.key = i;
        a.value  = i +1;
        CIntMapInsert(head,&a);
    }
}
