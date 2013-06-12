#include "CArray.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


CIntArray *CIntArrayCreate(int len )
{
    //int *ty = ;
    CIntArray * array_node = (CIntArray *)malloc(sizeof(CIntArray));
    if(array_node == NULL){
        return NULL;
    }
    array_node ->data = (int *)malloc(sizeof(int)*len);
    if(array_node ->data  == NULL){
        return NULL;
    }
    array_node ->len = len;

    return array_node;
}

void CIntArrayRelease(CIntArray * node)
{
    free(node->data);
    free(node);
}

CArray * CArrayCreate(int len,MallocDataFunc  func)
{
    CArray * array_node = (CArray *)malloc(sizeof(CArray));

    if(array_node == NULL){
        return NULL;
    }
    array_node->data =func(len);
    if(array_node ->data  == NULL){
        return NULL;
    }
    array_node ->len = len;

    return array_node;

}



