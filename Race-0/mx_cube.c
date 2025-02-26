void mx_printchar(char c);

static void print_top(int n) {
    for (int i = 0; i < n / 2 + 1; i++)
        mx_printchar(' ');
    mx_printchar('+');
    for (int i = 0; i < 2 * n; i++)
        mx_printchar('-');
    mx_printchar('+');
    mx_printchar('\n');
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2 - i; j++)
            mx_printchar(' ');
        mx_printchar('/');
        for (int j = 0; j < 2 * n; j++)
            mx_printchar(' ');
        mx_printchar('/');
        for (int j = 0; j < i; j++)
            mx_printchar(' ');
        mx_printchar('|');
        mx_printchar('\n');
    }
}

static void print_mid(int n) {
    mx_printchar('+');
    for (int i = 0; i < 2 * n; i++)
        mx_printchar('-');
    mx_printchar('+');
    for (int i = 0; i < n / 2; i++)
        mx_printchar(' ');
    mx_printchar('|');
    mx_printchar('\n');
}

static void print_bottom(int n) {
    for (int i = 0; i < n - n / 2 - 1; i++) {
        mx_printchar('|');
        for (int j = 0; j < 2 * n; j++)
            mx_printchar(' ');
        mx_printchar('|');
        for (int j = 0; j < n / 2; j++)
            mx_printchar(' ');
        mx_printchar('|');
        mx_printchar('\n');
    }
    mx_printchar('|');
    for (int j = 0; j < 2 * n; j++)
        mx_printchar(' ');
    mx_printchar('|');
    for (int j = 0; j < n / 2; j++)
        mx_printchar(' ');
    mx_printchar('+');
    mx_printchar('\n');
}

static void print_base(int n) {
    for (int i = 0; i < n / 2; i++) {
        mx_printchar('|');
        for (int j = 0; j < 2 * n; j++)
            mx_printchar(' ');
        mx_printchar('|');
        for (int j = 0; j < n / 2 - i - 1; j++)
            mx_printchar(' ');
        mx_printchar('/');
        mx_printchar('\n');
    }
    mx_printchar('+');
    for (int i = 0; i < 2 * n; i++)
        mx_printchar('-');
    mx_printchar('+');
    mx_printchar('\n');
}

void mx_cube(int n) {
    if (n < 2)
        return;

    print_top(n);
    print_mid(n);
    print_bottom(n);
    print_base(n);
}

