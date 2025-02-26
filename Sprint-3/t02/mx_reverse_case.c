#include <stdbool.h>

bool mx_islower(int c);
bool mx_isupper(int c);
int mx_tolower(int c);
int mx_toupper(int c);

void mx_reverse_case(char *c) {
    int i = 0;

    while (c[i] != '\0') {
        if (mx_isupper(c[i])) {
            c[i] = mx_tolower(c[i]);
        }
        else if (mx_islower(c[i])) {
            c[i] = mx_toupper(c[i]);
        }

        i++;
    }
}
