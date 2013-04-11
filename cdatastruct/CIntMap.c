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
CIntMap * CIntMapSort(CIntMap *  map_head, CompareDataFunc func ,SwapDataFunc swapfunc)
{

    CQsort(map_head->arr ,sizeof(struct CIntMapData_t), 0,map_head->len -1 ,func,swapfunc);

}
CIntMapData * CIntMapFind(CIntMap *  map_head, cint key )
{
    if(map_head->len == 0 ){
        return NULL;
    }
    int l = 0;
    int r = map_head->len -1;
    CIntMapData * data = map_head->arr;
    while(l <= r){
        int mid = l + (r-l)/2;
        int arr_key = data[mid].key;
        if( arr_key== key){
            return &(data[mid]);
        }else if(arr_key < key){
            l = mid + 1;
        }else {
            r = mid -1;
        }
    }

    return NULL;
}

/*
    以key 值来排序
*/
static int testCIntMapCompareData(struct CIntMapData_t *a ,struct CIntMapData_t *b )
{
    return (a->key)>(b->key)?1:(a->key)<(b->key)?-1:0;
}
static void testCIntMapSwap(struct CIntMapData_t *a ,struct CIntMapData_t *b ,int data_size)
{
    struct CIntMapData_t * temp = (struct CIntMapData_t *)malloc(data_size*sizeof(char));
     if(temp == NULL){
        exit(1);
    }
    memcpy(temp,a,data_size);
    memcpy(a,b,data_size);
    memcpy(b,temp,data_size);

    free(temp);
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
        a.key = (10-i);
        a.value  = i * i ;
        CIntMapInsert(head,&a);
    }

    CIntMapSort(head,testCIntMapCompareData,testCIntMapSwap );

    CIntMapData * mapdata_node = CIntMapFind(head , 2);
    if(mapdata_node != NULL)
        printf("%d %d\n",mapdata_node->key ,mapdata_node->value);


}
void testIntMapMain2()
{
    CIntMap * head;
    int n = 5000000 -1;
    head = CIntMapCreate(n,CIntMapDataMalloc);

    CIntMapData a;
    int i ;
    FILE *fp ;
    fp = fopen("in","r");
    for(i = 0 ; i < n ; i ++){
        fscanf(fp,"%d%d",&a.key,&a.value);
        CIntMapInsert(head,&a);
    }

    CIntMapSort(head,testCIntMapCompareData,testCIntMapSwap );
    CIntMapData * mapdata_node  = CIntMapFind(head , 2);
    for(i = 1 ; i < n ; i ++){
        mapdata_node  = CIntMapFind(head , i);
        if(mapdata_node != NULL)
            printf("%d %d \n",mapdata_node->key ,mapdata_node->value);
        else {
            printf("error ; %d not found \n",i);
        }
    }




}
