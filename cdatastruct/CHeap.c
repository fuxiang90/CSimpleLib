


#include "CHeap.h"

void CHeapNodeSwap( CHeap * head  , unsigned int a ,unsigned int b)
{
//    int *  t = (int *)(head->value_array + a);
//    *(head->value_array + a) = (int *) *(head->value_array + b);
//    *(head->value_array + b) = t;

    void * t =head->value_array[a];
    head->value_array[a] = head->value_array[b];
    head->value_array[b] = t;
}
CHeap * CHeapCreate(int cap)
{
    CHeap * head = (CHeap *)malloc(sizeof(CHeap));
    if(head == NULL){
        return NULL;
    }
    if(cap < MIN_CAP) cap = MIN_CAP;
    head->value_array = (void * * )malloc(sizeof(4) * cap);
    if(head->value_array  == NULL){
        free(head);
        return NULL;
    }

    head->free = NULL;
    head->compare = NULL;
    head->swap = NULL;
    head->size = 0;
    head->cap = cap;

    return head;
}
void CHeapInsert(CHeap * head ,void * value )
{
    if(CHeapIsFull(head) == 1 ){

    }

    head->value_array[head->size ] = value;
    head->size ++;
    CHeapUp(head , head->size -1 ); //保持堆的属性
}
void CHeapPush(CHeap * head ,void * value )
{
    if(CHeapIsFull(head) == 1 ){

    }

    head->value_array[head->size ] = value;
    head->size ++;

}
int CHeapIsFull(const CHeap* head)
{
    if(head->cap == head-> size)
        return 1 ;
    else
        return 0;
}

void CHeapUp(CHeap * head, unsigned int pos )
{
    unsigned int parent = HEAP_PARENT(pos);

    while(pos >= 0 &&  head->compare( head->value_array[parent]  , head->value_array[pos]) <  0){

        void *   t = head->value_array[parent] ;
        head->value_array[parent] = head->value_array[pos] ;
        head->value_array[pos] = t;
        pos = parent;
    }
}
void CHeapDown(CHeap * head , unsigned int pos)
{
    unsigned int left_child ;
    unsigned int right_child ;
    unsigned int next = 0;
    while( pos  < head->size ){
        next  = pos ;
        left_child = HEAP_LEFT(pos);
        right_child  = HEAP_RIGHT(pos);
        if(left_child < head->size &&
                        head->compare( head->value_array + left_child   , head->value_array + next ) < 0 ){
            next = left_child;
        }

        if(right_child < head->size &&
                        head->compare( head->value_array[right_child]  , head->value_array[next] ) < 0 ){
            next = right_child;
        }
        if(pos == next )
            break;

        CHeapNodeSwap(head , pos ,next);
        pos = next;


    }
    //CHeapPrint(head );
}
CHeap * CHeapMake( CHeap * head)
{
    int heap_size = head->size ;

    int i ;
    for( i = heap_size /2 ; i >= 0 ; i -- ){
        CHeapDown(head , i);
    }

    return head;
}
void CHeapRealse(CHeap* head)
{
    int i ;
    for(int i = 0  ; i < head->size ; i ++){
        if(head->free != NULL){
            head->free(head->value_array[i]);
        }else {
            free(head->value_array[i]);
        }
    }
}
static void CHeapPrint(CHeap * head )
{
    int i ;
    for(i = 0 ; i < head->size ; i ++){
        printf("%lf\n" ,( ( struct HeapNode_t*)(head->value_array[i]) ) -> key );
    }
}
static  int cmp(void * a ,void * b)
{
    if( ((HeapNode *)a)->key > ((HeapNode *)b)->key ){
        return 1;
    }else if( ((HeapNode *)a)->key < ((HeapNode *)b)->key ){
        return -1;
    }else {
        return 0;
    }

}
void testHeapMain()
{
    int i ;

    CHeap * head = CHeapCreate(10);
    CHeapSetCompareMethod(head ,cmp);
    CHeapSetFreeMethod(head ,cmp);
    for(i = 0 ; i < 10 ; i ++){


        HeapNode * new_heap_node = (HeapNode *) malloc(sizeof(HeapNode));
        new_heap_node->key = 10- i;
        CHeapPush(head ,new_heap_node);
        //CHeapInsert(head,new_heap_node);

    }
    CHeapPrint(head);
    printf("--------------------------\n");
    CHeapMake(head);
    CHeapPrint(head);

    CHeapRealse(head);


}
