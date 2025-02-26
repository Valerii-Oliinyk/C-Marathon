#include <stddef.h>

int mx_strcmp(const char *s1, const char *s2);

int mx_linear_search(char **arr, const char *s) {
    int i = 0;

    if (!arr || !s) {
        return -1;
    }

    while (arr[i] != NULL) {
        if (mx_strcmp(arr[i], s) == 0) {
            return i;
        }

        i = i + 1;
    }

    return -1;
}
