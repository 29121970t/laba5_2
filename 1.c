#include <limits.h>
#include <stdio.h>

#include "lib/parseLib5.h"

typedef struct StackFrame {
    int data;
    struct StackFrame* prev;
} StackFrame;

int isEmpty(StackFrame* stack) { return stack->prev == NULL; }
StackFrame* pushStack(StackFrame* stack, int data) {
    StackFrame* newFrame = malloc(sizeof(StackFrame));
    newFrame->data = data;
    newFrame->prev = stack;
    return newFrame;
}
int popStack(StackFrame** stackPtr) {
    StackFrame* newStack = (*stackPtr)->prev;
    int toRet = (*stackPtr)->data;
    free(*stackPtr);
    *stackPtr = newStack;
    return toRet;
}

StackFrame* createStack(void) { return malloc(sizeof(StackFrame)); }

void freeStack(StackFrame* stack) {
    StackFrame* t = NULL;
    while (stack->prev) {
        t = stack->prev;
        free(stack);
        stack = t;
    }
    free(stack);
}
void printStack(StackFrame* stack) {
    while (stack->prev) {
        printf("%d ", stack->data);
        stack = stack->prev;
    }
}
int peekStack(StackFrame* stack) { return stack->data; }

StackFrame* mergeStacks(StackFrame* highToLowStack, StackFrame* lowToHighStack) {
    StackFrame* stack3 = createStack();
    int s1_t = peekStack(highToLowStack);
    while (!isEmpty(lowToHighStack) && peekStack(lowToHighStack) >= s1_t) {
        stack3 = pushStack(stack3, popStack(&lowToHighStack));
    }
    while (!isEmpty(stack3) || !isEmpty(highToLowStack)) {
        if (peekStack(highToLowStack) >= peekStack(stack3)) {
            lowToHighStack = pushStack(lowToHighStack, popStack(&stack3));
        } else {
            lowToHighStack = pushStack(lowToHighStack, popStack(&highToLowStack));
        }
    }
}

int isInIntRange(long num) { return num <= INT_MAX && num >= INT_MIN; }

int main(void) {
    StackFrame* stack = createStack();
    char str[100] = {0};
    long count = readLongWithDialog_v("Please enter max stack size (natural number > 0): ", isG0);
    printf("%ld", count);
    for (long i = 0; i < count; i++) {
        sprintf(str, "Please enter %ld-th element: ", i);
        stack = pushStack(stack, readLongWithDialog_v(str, isInIntRange));
    }

    printStack(stack);

    freeStack(stack);
    return 0;
}