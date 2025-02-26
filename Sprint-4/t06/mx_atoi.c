#include <stdbool.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);

int mx_atoi(const char *src) {
    int sign = 1;
    int res = 0;

    if (!src) {
        return 0;
    }

    while (mx_isspace(*src)) {
        src = src + 1;
    }

    if (*src == '-') {
        src++;
        sign = -1;
    }
    else if (*src == '+') {
        src++;
    }

    while (mx_isdigit(*src)) {
        res = res * 10 + (*src - '0');
        src++;
    }

    return res * sign;
}
