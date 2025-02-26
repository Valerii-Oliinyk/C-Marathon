#include <stdlib.h>
#include <stdbool.h>

int *mx_copy_int_arr(const int *src, int size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
    int *temp = NULL;
    int count = 0;
    bool repeated = false;
    int i = 0;
    int j = 0;

    if (!src || src_size <= 0) {
        return NULL;
    }

    temp = malloc(dst_size);

    for (i = 0; i < src_size; i++) {
        for (j = 0; j < count; j++) {
            if (src[i] == temp[j]) {
                repeated = true;
                break;
            }
        }

        if (!repeated) {
            temp[count] = src[i];
            count++;
        }
    }

    dst_size = count;

    return mx_copy_int_arr(temp, count);
}
