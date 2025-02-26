void mx_printchar(char c);

void mx_print_alphabet(void) {
    int i = 'a';

    for (i = 'A'; i <= 'Y'; i = i + 2) {
        mx_printchar(i);
        mx_printchar(i+33);
    }

    mx_printchar('\n');
}
