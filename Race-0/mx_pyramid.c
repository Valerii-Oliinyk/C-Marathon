void mx_printchar(char c);

static void top(int n) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n - i - 1; j++)
            mx_printchar(' ');
        mx_printchar('/');
        for (int j = 0; j < i * 2 - 1; j++)
            mx_printchar(' ');
        mx_printchar('\\');
        if (i == 0) {
            mx_printchar('\n');
            continue;
        }
        for (int j = 0; j < i; j++)
            mx_printchar(' ');
        mx_printchar('\\');
        mx_printchar('\n');
    }
}

static void mid(int n) {
    for (int i = n / 2; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
            mx_printchar(' ');
        mx_printchar('/');
        for (int j = 0; j < i * 2 - 1; j++)
            mx_printchar(' ');
        mx_printchar('\\');
        if (i == 0) {
            mx_printchar('\n');
            continue;
        }
        for (int j = 0; j < n - i - 1; j++)
            mx_printchar(' ');
        mx_printchar('|');
        mx_printchar('\n');
    }
}

static void base(int n) {
    mx_printchar('/');

    for (int i = 0; i < 2 * n - 3; i++) {
        mx_printchar('_');
    }

    mx_printchar('\\');
    mx_printchar('|');
    mx_printchar('\n');
}

void mx_pyramid(int n) {
    if (n < 2) {
        return;
    }

    top(n);
    mid(n);
    base(n);
}
