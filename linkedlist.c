#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList{
    int data;
    struct linkedList *next;
}linkedList;

/**
 * 带头节点单链表初始化
 * @return linkedList
 */
linkedList *init(){
    linkedList *list;
    list = (linkedList*) malloc(sizeof (linkedList));
    list->next = NULL;
    return list;
}

/**
 * 头插法建立单链表
 * @param list
 * @param a
 * @param n
 * @return linkedList
 */
linkedList *headInsert(linkedList *list, const int a[], int n){
    linkedList *s;
    for (int i = 0; i < n; ++i) {
        s = (linkedList*) malloc(sizeof(linkedList));
        s->data = a[i];
        s->next = list->next;
        list->next = s;
    }
    return list;
}

/**
 * 尾插法建立单链表
 * @param list
 * @param a
 * @param n
 * @return linkedList
 */
linkedList *tailInsert(linkedList *list, const int a[], int n){
    linkedList *s, *r = list;
    for (int i = 0; i < n; ++i) {
        s = (linkedList*) malloc(sizeof(linkedList));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return list;
}

/**
 * 按索引查找节点
 * @param list
 * @param index
 * @return linkedList
 */
linkedList *getElement(linkedList *list, int index){
    linkedList *p = list->next;
    if (index == 0){
        return list;
    } else if (index < 0){
        return NULL;
    }
    for (int j = 1; p && j < index; ++j) {
        p = p->next;
    }
    return p;
}

/**
 * 按值查找节点
 * @param list
 * @param key
 * @return linkedList
 */
linkedList *locateElement(linkedList *list, int key){
    linkedList *p = list->next;
    while (p != NULL && p->data != key){
        p = p->next;
    }
    return p;
}

/**
 * 在索引i处插入值为key的节点
 * @param list
 * @return linkedList
 */
linkedList *insertNode(linkedList *list, int index, int key){
    linkedList *p = getElement(list, index),
    *s = (linkedList*) malloc(sizeof(linkedList));
    s->data = key;
    s->next = p->next;
    p->next = s;
    return p;
}

/**
 * 删除节点
 * @param list
 * @param index
 * @return linkedList
 */
void deleteNode(linkedList *list, int index){
    linkedList *p = getElement(list, index),
    *q = p->next;
    p->next = q->next;
    free(q);
}

/**
 * 打印单链表
 * @param list
 */
void print(linkedList *list){
    linkedList *s = list->next;
    while(s != NULL){
        printf("%d  ", s->data);
        s = s->next;
    }
}

/**
 * 获取表长
 * @param list
 * @return
 */
int getLength(linkedList *list){
    linkedList *p = list->next;
    int i = 0;
    while (p != NULL){
        p = p->next;
        i++;
    }
    return i;
}

int main(){
    linkedList *list = init();
    int a[] = {124,215,13,514,45};
    tailInsert(list, a, 5);
    deleteNode(list, 4);
    print(list);
    return 0;
}