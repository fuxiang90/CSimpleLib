#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CSlist.h"
#include "CArray.h"
#include "CIntMap.h"
#include "Csort.h"
#include "CMat.h"
struct tnode{
    int a;

};
void * myMalloc(int len){
   void *a = malloc(len*sizeof(struct tnode));

   return a;
}

void myPrint(struct tnode * value ){

	if(value != NULL){
		printf("%d\n",value->a);

	}
}

void myInput(struct tnode * value,int key ){

	value->a = key;
}

int main()
{
    /* array test
    CArray * array_node = CArrayCreate(10,myMalloc);
    int i = 0;
    for( i = 0 ; i < array_node->len ; i ++){
    	//( (struct tnode *) ( (array_node->data)+i ) )->a) = i;
    	//myInput( (array_node->data)+i   ,i);

    	myInput((struct tnode*)(array_node->data) + i, i);
    }
    for( i = 0 ; i < array_node->len ; i ++){
        //printf("%d\n", ( (struct tnode *) ( (array_node->data)+i ) )->a);
    	//myPrint((array_node->data)+i );
    	myPrint((struct tnode*)(array_node->data) + i);
    }
    */

    //testIntMapMain();
    //testIntMapMain2();
    //testSortMain();

    //testMat();
//    testHeapMain();


//    CArrayTest();
//
//
//    int size_a =  (128  +128 )*1024 ;
//    int size_b = 10 * 1024;
//    char * str = (char *) malloc(size_b);
//    //0804d000     140 rw--- 0000000000000000 000:00000   [ anon ]
//
//
//    int i ;
//    stpcpy(str,"hello");
//
//    free(str);
//    //0804d000     132 rw--- 0000000000000000 000:00000   [ anon ]
//
//
//
//    str = (char *)malloc(size_a);
//
//    free(str);
//
//    for( i = 0 ; i < 10 ; i ++){
//        str = (char *)malloc(size_b);
//    }
    testHeapMain();
    //testList();
    return 0;
}
