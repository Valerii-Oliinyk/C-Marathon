#include <stdbool.h>

int mx_toupper(int c) {
    if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }

    return c;
}
