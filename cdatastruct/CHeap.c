


#include "CHeap.h"


CHeap * CHeapCreate(int cap)
{
    CHeap * head = (CHeap *)malloc(sizeof(CHeap));
    if(head == NULL){
        return NULL;
    }
    if(cap < MIN_CAP) cap = MIN_CAP
    head->heap_array = (HeapNode * * )malloc(sizeof(HeapNode * )*(cap));
    if(head->heap_array  == NULL){
        free(head);
        return NULL;
    }

    head->size = 0;
    head->cap = cap;

    return head;
}
CHeap * CHeapInsert(CHeap * head ,void * value )
{
    if(CHeapIsFull(head) == 1 ){

    }

    head->value_array[head->size + 1] = value;
    head->size ++;


}

int CHeapIsFull(const heap* head)
{
    if(head->cap == head-> size)
        return 1 ;
    else
        return 0;
}



void testHeapMain()
{
    int i ;

    CHeap * head = CHeapCreate(10);
    for(i = 0 ; i < 10 ; i ++){

        struct node_t * new_node = (struct node_t*)malloc(sizeof(struct node_t));
        new_node ->d = rand() % 100;
        new_node ->value = i;
        HeapNode * new_heap_node = (HeapNode *) malloc(sizeof(HeapNode));

        new_heap_node->data = new_node;
        new_heap_node->key = new_node->d ;

        CHeapInsert(head,new_heap_node);

    }
    CHeapPrint(head);
    printf("--------------------------\n");
    CHeapBuild(head,cmp);
    CHeapPrint(head);



}
