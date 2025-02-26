#include <stddef.h>
#include <stdbool.h>

bool mx_isspace(char c);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);
char *mx_strtrim(const char *str);

char *mx_del_extra_whitespaces(const char *str) {
    char *trimmed = NULL;
    int len = 0;
    char *result = NULL;
    int i = 0;
    int j = 0;

    if (!str) {
        return NULL;
    }

    trimmed = mx_strtrim(str);

    if (!trimmed) {
        return NULL;
    }

    len = mx_strlen(trimmed);
    result = mx_strnew(len);

    if (!result) {
        mx_strdel(&trimmed);

        return NULL;
    }

    while (trimmed[i]) {
        if (mx_isspace(trimmed[i])) {
            result[j++] = ' ';

            while (mx_isspace(trimmed[i])) {
                i++;
            }
        }
        else {
            result[j++] = trimmed[i++];
        }
    }

    mx_strdel(&trimmed);

    return result;
}
