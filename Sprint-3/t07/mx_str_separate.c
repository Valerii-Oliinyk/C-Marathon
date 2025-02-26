#include <unistd.h>

void mx_printchar(char c);

void mx_str_separate(const char *str, char delim) {
    if (!str) return;

    while (*str) {
        if (*str == delim) {
            mx_printchar('\n');
        }
        else {
            mx_printchar(*str);
        }

        str++;
    }

    mx_printchar('\n');
}
