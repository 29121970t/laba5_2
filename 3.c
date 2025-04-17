#include <stdio.h>
#include <stdlib.h>

#include "lib/mStack.h"
#include "lib/parseLib5.h"
#include "lib/RPN.h"

int main(int argc, char const* argv[]) {
    char* str1 = NULL;
    size_t strLen = 0;
    if (argc < 3) {
        printf("Not enought arguments. Please specify input and output files.\n");
        exit(1);
    }
    FILE* inputFile = fopen(argv[1], "r");
    FILE* outputFile = fopen(argv[2], "w+");
    strLen = getLine(&str1, inputFile);
    while (strLen) {
        int errorCode = 0;
        if ((errorCode = validateInputString(str1)) > -1) {
            fprintf(outputFile, "Error at position %d\n", errorCode + 1);
            free(str1);
            strLen = getLine(&str1, inputFile);
            continue;
        }

        char* RPL = toRevercePolishNotation(str1, 100);
        free(str1);
        strLen = getLine(&str1, inputFile);
        fprintf(outputFile, "%lf\n", clalcRPN(RPL));
        free(RPL);

    }
    free(str1);



    return 0;
}
