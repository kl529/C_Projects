#include <stdio.h>
#include <stdlib.h>

typedef struct stack{//스텍이라는 구조체
    int top;
    int capacity;
    int* array;//배열을 포인트로 씀
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));//스텍 구조체 만큼 공간확보에 대한 주소를 stack포인터에 줌
    stack->capacity = capacity;//input 값으로 들어온 capacity를 넣어줌
    stack->top = -1;//top은 -1
    stack->array = (int *)malloc(stack->capacity*sizeof(int));//배열은 스텍의 수용수만큼 int형으로 공간확보
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity-1;//꽉차면 true
}

int isEmpty(Stack* stack) {
    return stack->top == -1;//비어있으면 true
}

void push(Stack* stack, int item) { //쌓기 item이 들어갈 값
    if (isFull(stack))//다차면 관두기
        return;
    stack->array[++stack->top] = item;//스텍구조체의 top에서 하나 더쌓음
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {//top 삭제
    if(isEmpty(stack))//비어있지다면 관두기
        return -9999;
    int popnum = stack->array[stack->top];//pop할 값 저장
    stack->top -= 1;//1삭제하고
    return popnum;
}

int peek(Stack* stack) {//top 출력
    if(isEmpty(stack))//비어있지다면 관두기
        return 1;
    return stack->array[stack->top];
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));

    push(stack, 50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    return 0;
}
