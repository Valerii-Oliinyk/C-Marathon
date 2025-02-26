#include <stdio.h>
#include <stdbool.h>

int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strchr(const char *s, int c);

char *mx_strstr(const char *s1, const char *s2) {
    char* substr = (char*)s1;

    while (mx_strchr(substr, *s2) != NULL) {
        if (mx_strncmp(mx_strchr(substr, *s2), s2, mx_strlen(s2)) == 0) {
            return mx_strchr(substr, *s2);
        }

        substr = mx_strchr(substr, *s2) + 1;
    }

    return NULL;
}
