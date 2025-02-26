#include <stdio.h>

int mx_sqrt(int x) {
    int i = 0;

    if (x < 0) {
        return 0;
    }

    for (i = 0; i * i <= x && i <= 46340; i++) {
        if (i * i == x) {
            return i;
        }
    }

    return 0;
}
