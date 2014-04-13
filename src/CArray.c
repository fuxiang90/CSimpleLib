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


//下面两个函数来自 云风大哥的开源代码
//https://github.com/cloudwu/buddy/blob/master/buddy.c
static  int is_pow_of_2(unsigned int x)
{
	return !(x & (x-1));
}
/*
*
*/
static  unsigned int  next_pow_of_2(unsigned int x)
{
	if ( is_pow_of_2(x) )
		return next_pow_of_2(x+1);
	x |= x>>1;
	x |= x>>2;
	x |= x>>4;
	x |= x>>8;
	x |= x>>16;
	return x+1;
}

//void CArrayRealloc()

CArray* CArrayCreate( int cap ,int data_size)
{
    CArray * array_ptr = (CArray * )malloc(sizeof(CArray));

    if(array_ptr  ==NULL){
        fprintf(stdout,"CArrayCreate memory error\n");
        return NULL;
    }
    if(cap < MIN_ARRAY_SIZE)
        cap = MIN_ARRAY_SIZE;
    array_ptr->cap = cap;
    array_ptr->len = 0;
    array_ptr->data_size =data_size;

    array_ptr->data = malloc(data_size * cap);
    if(array_ptr == NULL){
        fprintf(stdout,"CArrayCreate memory error\n");
        return NULL;
    }

    return array_ptr;
}
void CArrayRelease(CArray * array_ptr)
{
    if(array_ptr == NULL) return ;

    if(array_ptr ->data ){
        if(array_ptr->free){
            array_ptr->free(array_ptr->data);
        }else{
            free(array_ptr->data);
        }
    }

    free(array_ptr);
    array_ptr = NULL;
}

int CArrayPush(CArray * array_ptr , void * value)
{
    if(array_ptr ->len == array_ptr->cap){
        int new_cap = next_pow_of_2(array_ptr->cap);

        void * new_data = realloc(array_ptr->data , new_cap * (array_ptr->data_size) );
        if(new_data == NULL){
            fprintf(stdout,"CArrayPush memory error\n");
            return 0;
        }
        array_ptr->data = new_data;


    }
    memcpy(array_ptr->data + (array_ptr->len)*(array_ptr->data_size)  ,value , array_ptr->data_size );
    array_ptr->len ++;
    return 1;



}

void CArrayTest()
{
    int i = next_pow_of_2(10);
    i = next_pow_of_2(16);

    CArray * array_ptr = CArrayCreate(10,sizeof(int));

    for(i = 0 ; i < 20 ; i ++){
        CArrayPush(array_ptr , &i);
    }


}

