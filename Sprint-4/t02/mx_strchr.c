#include <stddef.h>

char *mx_strchr(const char *s, int c) {
    int i = 0;
    
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == (char)c) {
            return (char *)&s[i];
        }
    }

    if (c == '\0') {
        return (char *)&s[0];
    }

    return NULL;
}
