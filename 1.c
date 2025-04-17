#include <limits.h>
#include <stdio.h>

#include "lib/parseLib5.h"
#include "lib/mStack.h"


int isInIntRange(long num) { return num <= INT_MAX && num >= INT_MIN; }

int main(void) {
    StackFrame* stack = createStack();
    char str[100] = { 0 };
    long count = readLongWithDialog_v("Please enter max stack size (natural number > 0): ", isG0);
    for (long i = 0; i < count; i++) {
        sprintf(str, "Please enter %ld-th element: ", i);
        stack = pushStack(stack, readLongWithDialog_v(str, isInIntRange));
    }
    int min = INT_MAX;
    int temp = 0;
    for (size_t i = 0; !isEmpty(stack); i++) {
        if ((temp = popStack(&stack))< min) min = temp;
    }

    printf("min value on a stack was %d\n", min);
    freeStack(stack);
    return 0;
}