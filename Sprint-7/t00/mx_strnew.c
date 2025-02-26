#include <stdlib.h>

char *mx_strnew(const int size) {
    char *pointer = 0;
    int i = 0;

    if (size < 0) {
        return NULL;
    }

    pointer = (char *)malloc(size+1);

    if (!pointer) {
        return NULL;
    }

    for (i = 0; i <= size; i++) {
        pointer[i] = '\0';
    }

    return pointer;
}
