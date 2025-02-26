#include <stdbool.h>

char *mx_strncpy(char *dst, const char *src, int len) {
    bool finish = false;
    int i = 0;

    for (i = 0; i < len; i++) {
        if (finish) {
            dst[i] = '\0';
        }
        else {
            dst[i] = src[i];
            if (src[i] == '\0') {
                finish = true;
            }
        }
    }
    return dst;
}
