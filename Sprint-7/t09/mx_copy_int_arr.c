#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size) {
    int *copy = 0;
    int i = 0;

    if (!src || size <= 0) {
        return NULL;
    }

    copy = (int *)malloc(size);

    if (!copy) {
        return NULL;
    }

    for (i = 0; i < size; i++) {
        copy[i] = src[i];
    }

    return copy;
}
