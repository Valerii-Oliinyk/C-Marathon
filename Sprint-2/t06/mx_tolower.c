#include <stdbool.h>

int mx_tolower(int c) {
    if (c >= 'A' && c <= 'Z') {
        c = c + ('a' - 'A');
    }

    return c;
}
