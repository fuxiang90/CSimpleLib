#ifndef CHEAP_H_INCLUDED
#define CHEAP_H_INCLUDED


#include "CCommon.h"
#ifdef __cplusplus
extern "C" {
#endif

/*用数组构建一个堆 ，默认是最小堆
数组下标从0开始 方便 找到左右子树

*/

typedef int (heap_compare)(void * ,void *);



#define MIN_CAP  32


typedef struct HeapNode_t HeapNode;
struct HeapNode_t {
    double key;
};


typedef struct CHeap_t CHeap;
struct CHeap_t {

    void * * value_array; //储存一些地址
    int     size;// 当前的大小
    int     cap;//容量
    int  (*compare) ( void *a  ,void * b);
    void (*free)    (void *ptr);
    void (*swap)   (void *a  ,void * b);

};
#define CHeapSetFreeMethod(l,m) ((l)->free = (m))
#define CHeapSetCompareMethod(l,m) ((l)->compare = (m))
#define HEAP_LEFT(nodo) ((nodo)+(nodo)+1)
#define HEAP_RIGHT(nodo) ((nodo)+(nodo)+2)
#define HEAP_PARENT(nodo) (((nodo)-1)>>1)


CHeap * CHeapCreate(int cap);



/*重建一个heap*/
CHeap * CHeapMake( CHeap * head);

void  CHeapInsert(CHeap*, void * value);
/*只是往之后插入 但是没有保持堆的性质*/
void CHeapPush(CHeap * head ,void * value );

void *  CHeapGetMin(const CHeap* head);

void CHeapDeleteMin( CHeap* head ) ;

void CHeapRealse(CHeap* head);

int CHeapIsEmpty(const CHeap*);

int CHeapIsFull(const CHeap*);

void CHeapUp(CHeap *, unsigned int pos );

void CHeapDown(CHeap * head , unsigned int pos);

void CHeapSift(CHeap * head );

void CHeapNodeSwap( CHeap * head  , unsigned int a ,unsigned int b);



static void CHeapPrint(CHeap * head );

static  int cmp(void * a ,void * b) ;







void testHeapMain();




#ifdef __cplusplus
}
#endif

#endif // CHEAP_H_INCLUDED
