#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

/**
 * 栈
 */
typedef struct {
    int data[MaxSize];
    int top;
}stack;

/**
 * 初始化一个栈
 * @return
 */
stack *init(){
    stack *s = (stack*) malloc(sizeof(stack));
    s->top = -1;
    return s;
}

/**
 * 判断栈是否为空
 * @param s
 * @return
 */
int isEmpty(stack *s){
    if (s->top == -1){
        return 1;
    } else{
        return 0;
    }
}

/**
 * 入栈
 * @param s
 * @param key
 * @return
 */
int push(stack *s, int key){
    if (s->top == MaxSize -1){
        return -1;
    } else{
        s->data[++s->top] = key;
        return 1;
    }
}

/**
 * 出栈
 * @param s
 * @return
 */
int pop(stack *s){
    if (s->top == -1){
        return -1;
    } else{
        return s->data[--s->top];
    }
}

/**
 * 打印栈内元素
 */
void printStack(stack *s){
    for (int i = 0; i < s->top + 1; ++i) {
        printf("%d ", s->data[i]);
    }
}

int main(){
    stack *s = init();
    push(s,10);
    printStack(s);
}