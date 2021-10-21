#include <stdio.h>
#include <stdlib.h>

/**
 * 双链表，其他操作均与单链表操作相同，仅插入删除不同
 */
typedef struct dLinkedList{
    int data;
    struct dLinkedList *prior, *next;
}dLinkedList;


