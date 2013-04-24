#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CSlist.h"
#include "Carray.h"
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

    testMat();

    printf("Hello worl\n");
    return 0;
}
