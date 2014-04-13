

#include "Csort.h"




int CPartition(void * data ,int data_size ,int s ,int e , CompareDataFunc func ,SwapDataFunc swapfunc)
{
    int p = s;
    int i = s;
    int j = s+ 1;


    for( ; j<= e ; j++){
        //if( func (&data[j] ,&data[p]) < 0){
        if( func (data + j*data_size ,data + p*data_size) < 0){
            i ++;
            //对于void * 指针 data[j] 相当于 只 data + j 纯数字 不会加上偏移量
            //swapfunc(&data[j],&data[i],data_size);
            swapfunc(data + j*data_size,data + i *data_size,data_size);

        }
    }
    swapfunc(data + p*data_size,data + i *data_size,data_size);
    //swapfunc(&data[p],&data[i],data_size);
    return i;
}

void CQsort(void * data ,int data_size , int s ,int e ,CompareDataFunc func,SwapDataFunc swapfunc)
{
    if(s >= e){
        return ;
    }

    int pos = CPartition(data,data_size,s,e,func,swapfunc);

    CQsort(data,data_size,s,pos-1,func,swapfunc);
    CQsort(data,data_size,pos+1,e,func,swapfunc);
}

/*test*/

static void testSwap(int * a ,int *b,int data_size){
    int *t = (int *) malloc(sizeof(char)*data_size);
    if(t == NULL){
        exit(1);
    }
    memcpy(t ,a ,data_size);
    memcpy(a,b,data_size);
    memcpy(b,t,data_size);
    free(t);

}

static int testCompare(int * a ,int *b)
{
    if(*a > *b)
        return 1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}

void testSortMain()
{
    int data[10] = {10,2,3,4,5,-2,1,3,10000,-2};
    int i;
    CQsort(data,4,0,9,testCompare,testSwap);
    for(i = 0 ; i < 10 ; i ++){
        printf("%d\n",data[i]);
    }

}
