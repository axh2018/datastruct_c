#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

/**
 * 队列
 */
typedef struct {
    int data[MaxSize];
    int front, rear;
}sqQueue;

sqQueue *init(){
    sqQueue *s = (sqQueue*) malloc(sizeof(sqQueue));
}