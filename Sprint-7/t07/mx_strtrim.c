#include <stddef.h>
#include <stdbool.h>

bool mx_isspace(char c);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);

char *mx_strtrim(const char *str) {
    int start = 0;
    int end = 0;
    int len = 0;
    char *trimmed = NULL;

    if (!str) {
        return NULL;
    }

    end = mx_strlen(str) - 1;

    while (mx_isspace(str[start])) {
        start++;
    }

    while (end > start && mx_isspace(str[end])) {
        end--;
    }

    len = end - start + 1;
    trimmed = mx_strnew(len);

    if (!trimmed) {
        return NULL;
    }

    mx_strncpy(trimmed, str + start, len);

    return trimmed;
}
