#include <limits.h>
#include <stdio.h>

#include "lib/parseLib5.h"
#include "lib/mStack.h"

int checkHighToLow(long num) {
    static long prevNum = LONG_MAX;
    int res = num <= INT_MAX && num >= INT_MIN && num <= prevNum;
    if (res) prevNum = num;
    return res;
}
int checkLowToHigh(long num) {
    static long prevNum = LONG_MIN;
    int res = num <= INT_MAX && num >= INT_MIN && num >= prevNum;
    if (res) prevNum = num;
    return res;
}

int main(void) {
    StackFrame* highToLowStack = createStack();
    StackFrame* lowToHighStack = createStack();
    char str[100] = {0};
    long count = readLongWithDialog_v("Please enter max stack size (natural number > 0): ", isG0);
    for (long i = 0; i < count; i++) {
        sprintf(str, "Please enter %ld-th element: ", i + 1);
        long el = readLongWithDialog_v(str, checkHighToLow);
        highToLowStack = pushStack(highToLowStack, el);
    }
    count = readLongWithDialog_v("Please enter max stack size (natural number > 0): ", isG0);
    for (long i = 0; i < count; i++) {
        sprintf(str, "Please enter %ld-th element: ", i + 1);
        long el = readLongWithDialog_v(str, checkLowToHigh);
        lowToHighStack = pushStack(lowToHighStack, el);
    }
    printStack(highToLowStack);
    printStack(lowToHighStack);
    puts("");
    printStack(mergeStacks(highToLowStack, lowToHighStack));
    return 0;
}