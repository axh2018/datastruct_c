#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef struct {
    int data[MaxSize];
    int length;
}seqList;

/**
 * 初始化操作
 * @return seqList
 */
seqList *initList()
{
    seqList *pSeqList = (seqList *)malloc(sizeof(seqList));
    if (pSeqList == NULL)
    {
        printf("初始化失败\n");
        exit(-1);
    }

    pSeqList->length = 0;
    return pSeqList;
}

/**
 * 顺序表插入操作
 * @param seqList
 * @param key
 * @return
 */
int insertItem(seqList *seqList, int index, int key){
    if (index < 0 || index > seqList->length || seqList->length >= MaxSize){
        printf("index not valid\n");
        return 0;
    }else{
        for (int i = seqList->length; i >= index; i--) {
            seqList->data[i] = seqList->data[i-1];
        }
        seqList->data[index] = key;
        seqList->length++;
        return 1;
    }
}

/**
 * 删除索引所在元素
 * @param seqList
 * @param index
 * @return
 */
int deleteItem(seqList *seqList, int index){
    if(seqList->length == 0){
        printf("长度为0，无法删除");
        return 0;
    } else if(index >= seqList->length || index < 0){
        printf("index is not valid");
        return 0;
    } else{
        //删除操作
        for (int i = index; i < seqList->length; ++i) {
            seqList->data[i] = seqList->data[i+1];
        }
        seqList->length--;
        return 1;
    }
}

/**
 * 根据元素索引获取元素
 */
int getItem(seqList seqList, int index){
    if(index >= seqList.length || index < 0){
        printf("index is not valid");
    } else{
        return seqList.data[index];
    }
}

/**
 * 修改索引所在元素的值
 * @return
 */
int updateItem(seqList *seqList, int index, int key){
    if (index >= seqList->length || index < 0){
        printf("index is not valid");
        return 0;
    } else{
        seqList->data[index] = key;
        return 1;
    }
}

/**
 * 打印顺序表
 * @param list
 * @return
 */
void printList(seqList list){
    if (list.length == 0){
        printf("seqList length is 0");
    } else{
        for (int i = 0; i < list.length; ++i) {
            printf("%d  ", list.data[i]);
        }
    }
}

int main() {
    seqList  *list = initList();
    insertItem(list, 0, 1);
    insertItem(list, 1, 2);
    insertItem(list, 2, 3);
    printList(*list );
    printf("\n");
    deleteItem(list, 0);
    printList(*list);
    return 0;
}