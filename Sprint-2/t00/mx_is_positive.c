#include <unistd.h>

int mx_strlen(const char *s);
void mx_printstr(const char *s);

void mx_is_positive(int i) {
    if (i < 0) {
        mx_printstr("negative\n");
    }
    else if (i == 0) {
        mx_printstr("zero\n");
    }
    else if (i > 0) {
        mx_printstr("positive\n");
    }
}
