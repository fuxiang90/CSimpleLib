
#include"CSlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int  CSlistMatch(struct value_t * key_a ,struct value_t*  key_b )
{
    if(key_a->data == key_b ->data &&  0==strcmp(key_a->str ,key_b->str))
        return 1;
    return 0;
}

CSlist *CSlistCreate(void)
{
    CSlist * l = (CSlist *)malloc(sizeof(CSlist));
    if(l == NULL){
        return NULL;
    }
    l->len = 0;
    l->head = NULL;
    l->tail = NULL;

    return l;
}
void CSlistRelease(CSlist * l)
{
    CSlist * l_temp = l;
    CSlistNode * list_node =l->head;
    CSlistNode * next_node;
    while(list_node!= NULL ){
        next_node = list_node ->next;
        free(list_node->value);
        free(list_node);
        list_node = next_node;
    }

    free(l_temp);

}

CSlist *CSlistAddNodeHead(CSlist *l, void *value)
{
    CSlistNode *list_node = (CSlistNode * )malloc(sizeof(CSlistNode));
    list_node->next = NULL;
    list_node->value = value;
    if(l->len == 0){
        l->head = list_node;
        l->tail = list_node;
        l->len ++;
    }else {
        list_node->next = l->head;
        l->head = list_node;
        l->len ++;
    }

    return l;
}
CSlist *CSlistAddNodeTail(CSlist *l, void *value)
{
    CSlistNode * list_node = (CSlistNode * )malloc(sizeof(CSlistNode));
    list_node->next = NULL;
    list_node->value = value;
    if(l->len == 0){
        l->head = list_node;
        l->tail = list_node;
        l->len ++;
    }else {
        l->tail->next = list_node;
        l->tail = list_node;
        l->len ++;
    }

    return l;

}


CSlist *CSlistInsertNode(CSlist *l, CSlistNode *old_node, void *value)
{
    CSlistNode * list_node = (CSlistNode * )malloc(sizeof(CSlistNode));
    list_node->next = NULL;
    list_node->value = value;

    list_node ->next = old_node->next;
    old_node->next = list_node;

    l->len ++;
    return l;
}
void CSlistDelNode(CSlist *l, CSlistNode *node)
{
    CSlistNode *list_node = l->head;
    CSlistNode *pre_node = list_node;
    while(list_node != node){
        pre_node = list_node;
        list_node = list_node->next;

    }

    if(list_node == pre_node){
        l->head = l->head->next;

    }else{
        pre_node ->next = list_node->next;

    }
    l->len --;
    free(list_node->value);
    free(list_node);
}
CSlistNode *CSlistSearchKey(CSlist *l, void *key)
{
    CSlistNode *list_node = l->head;
    while(list_node){
        if(CSlistMatch(key, list_node->value) == 1){
            return list_node;
        }
        list_node = list_node -> next;

    }
    return NULL;

}

void CSlistPrint(CSlist * l)
{
    CSlistNode *list_node = l->head;
    while(list_node){

        printf("%d\n",( (struct value_t *)(list_node->value) )->data );
        printf("%s\n",( (struct value_t *)(list_node->value) )->str );
        list_node = list_node -> next;

    }
}


////

void testList()
{
//    CSlist * l = CSlistCreate();
//    struct value_t a[10];
//    char *str = "hello";
//    int i ;
//    for(i = 0 ; i < 10;i++){
//        a[i].str = (char *) malloc(sizeof(str)+ 1);
//        strcpy(a[i].str ,str);
//        a[i].data = i;
//        l = CSlistAddNodeHead(l,&a[i]);
//    }
//    CSlistPrint(l);
}
