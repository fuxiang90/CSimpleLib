#ifndef CSLIST_H_INCLUDED
#define CSLIST_H_INCLUDED

typedef struct CSlistNode_t  CSlistNode;
struct CSlistNode_t {
    struct CSlistNode_t *next;
    void * value;
};
typedef struct CSlist_t  CSlist;
struct CSlist_t{
    struct CSlistNode_t * head;
    struct CSlistNode_t * tail;
    unsigned int len;

};

struct value_t{

    int data;
    char *str;
};

#define CSlistLength(l) ((l)->len)
#define CSlistFirst(l) ((l)->head)
#define CSlistLast(l) ((l)->tail)


CSlist *CSlistCreate(void);
void CSlistRelease(CSlist * l);
CSlist *CSlistAddNodeHead(CSlist *l, void *value);
CSlist *CSlistAddNodeTail(CSlist *l, void *value);
//CSlist *CSlistInsertNode(CSlist *l, listNode *old_node, void *value, int after);
CSlist *CSlistInsertNode(CSlist *l, CSlistNode *old_node, void *value);
void CSlistDelNode(CSlist *l, CSlistNode *node);
//listIter *CSlistGetIterator(list *list, int direction);
//CSlistNode *listNext(listIter *iter);
//void listReleaseIterator(listIter *iter);
CSlist *listDup(CSlist *orig);
CSlistNode *CSlistSearchKey(CSlist *l, void *key);
CSlistNode *CSlistIndex(CSlist *l, int index);
//void listRewind(CSlist *l, listIter *li);
//void listRewindTail(CSlist *l, listIter *li);

void CSlistPrint(CSlist * l);

#endif // CSLIST_H_INCLUDED
