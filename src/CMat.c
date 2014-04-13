
#include "CMat.h"

CMat *CMatCreate(int row ,int col)
{
    CMat * m = (CMat*)malloc(sizeof(struct CMat_t));
    if(m == NULL) return NULL;

    int n = row * col;

    if( ( m->data  = (double *)malloc(sizeof(double )*n) ) == NULL ){
        return NULL;
    }

    m->row = row;
    m->col = col;

    return m;
}
void CMatRelease(CMat * m)
{
    free(m->data);
    m->data = NULL;
    free(m);
    m = NULL;
}


void testMat()
{
    CMat * m = CMatCreate(10,10);

    int i ,j;
    for( i = 0 ; i < 10 ; i ++ ){
        for( j = 0 ; j < 10 ; j ++){
            m->data[i*m->col  +j] = i *10 + j;
        }
    }

     for( i = 0 ; i < 10 ; i ++ ){
        for( j = 0 ; j < 10 ; j ++){
                printf("%lf\n" ,m->data[i*m->col  +j] = i *10 + j);
        }
    }



}
