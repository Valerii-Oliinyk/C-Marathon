#include <stddef.h>

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *str) {
    int size = 0;
    char *pointer = 0;

    if (!str) {
        return NULL;
    }

    size = mx_strlen(str);
    pointer = mx_strnew(size);

    if (!pointer) {
        return NULL;
    }

    return mx_strcpy(pointer, str);
}
