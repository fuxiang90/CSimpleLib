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

#define HEAP_LEFT(nodo) ((nodo)+(nodo)+1)
#define HEAP_RIGHT(nodo) ((nodo)+(nodo)+2)
#define HEAP_PARENT(nodo) (((nodo)-1)>>1)

#define MIN_CAP  32

typedef struct HeapNode_t HeapNode;

 struct HeapNode_t {
    double key;
    void *data;
};


typedef struct CHeap_t CHeap;
struct CHeap_t {

    void *  value_array; //储存一些地址
    int     size;// 当前的大小
    int     cap;//容量
    heap_compare * compare ;
    void (*free)(void *ptr);

};



CHeap * CHeapCreate(int cap);

CHeap * CHeapInsert(CHeap * head ,HeapNode * node );

CHeap * CHeapMake( CHeap * head);

void CHeapInsert(CHeap*, void * value);

void *  CHeapFindMin(const CHeap*);

/*
	Busca el elemento con la máxima prioridad, o sea el mínimo índice, y lo
	saca del heap, reestructurando el montículo.
	O(log n)
*/

unsigned int CHeapDeleteMin(CHeap*);



void CHeapRealse(CHeap*);

int CHeapIsEmpty(const heap*);
int CHeapIsFull(const heap*);
/*
	Reestructura el heap luego de haber cambiado alguna prioridad, pasando a
	prioridad mas alta (índice mas bajo).
	El parámetro es el índice del arreglo interno del heap por donde se desea
	arreglar las posibles violaciones de la propiedad min-heap.
	Ver node.heap_index.

*/
void CHeapHeapifUp(CHeap *, void * );



void CHeapSift(CHeap * head );

void CHeapNodeSwap(HeapNode * a ,HeapNode * b);

CHeap * CHeapBuild(CHeap * head , int (*cmpFun)(void * a ,void * b) );

void CHeapPrint(CHeap * head);

static  int cmp(void * a ,void * b) ;
//HeapNode * HeapNodeCreate(int data_size)


struct node_t {
    double d; //以这个作为排序的根据
    int value;

};



void testHeapMain();




#ifdef __cplusplus
}
#endif

#endif // CHEAP_H_INCLUDED
