#include <stddef.h>

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char *s1, const char *s2);

char *mx_strjoin(char const *s1, char const *s2) {
    int len1 = 0;
    int len2 = 0;
    char *new_str = 0;

    if (!s1 && !s2) {
        return NULL;
    }

    if (!s1) {
        return mx_strdup(s2);
    }

    if (!s2) {
        return mx_strdup(s1);
    }

    len1 = mx_strlen(s1);
    len2 = mx_strlen(s2);
    new_str = mx_strnew(len1 + len2);

    if (!new_str) {
        return NULL;
    }

    mx_strcpy(new_str, s1);
    mx_strcat(new_str, s2);

    new_str[len1 + len2] = '\0';

    return new_str;
}
