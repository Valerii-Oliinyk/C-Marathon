#include <stdbool.h>

void mx_printchar(char c);
int mx_atoi(const char *src);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printint(int n);

int main(int argc, char *argv[]) {
    int i = 1;
    int digit = 0;
    int sum = 0;

    if (argc < 2) {
        return 0;
    }

    while (i < argc) {
        digit = mx_atoi(argv[i]);

        if (digit != 0) {
            sum = sum + digit;
        }

        i = i + 1;
    }

    mx_printint(sum);
    mx_printchar('\n');
}
