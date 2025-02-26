#include <unistd.h>

int mx_strlen(const char *s);

void mx_printstr(const char *s) {
    int length = mx_strlen(s);

    for (int i = 0; i < length; i++) {
        write(1, &s[i], 1);
    }
}
