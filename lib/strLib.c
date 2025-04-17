#include "strLib.h"

int strcopm(char* s1, char* s2) {
    for (size_t i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i]) return 0;
    }
    return 1;
}
void _strcpy(char* dest, char* src) {
    for (size_t i = 0; src[i]; i++) {
        dest[i] = src[i];
    }
}

void* memcpy(void* dest, const void* src, size_t len) {
    char* d = dest;
    const char* s = src;
    while (len--) *d++ = *s++;
    return dest;
}
