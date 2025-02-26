#include <stdbool.h>
#include <stdio.h>

int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strchr(const char *s, int c);
char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
    int res = 0;

    if (mx_strlen(sub) == 0) {
        return 0;
    }

    while (mx_strstr(str, sub) != NULL) {
        res++;
        str = mx_strstr(str, sub) + 1;
    }

    return res;
}
