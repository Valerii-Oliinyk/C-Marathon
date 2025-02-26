int mx_strlen();
void mx_swap_char();

void mx_str_reverse(char *s) {
    int length = mx_strlen(s);
    int i = 0;
    int middle = 0;

    if (length % 2 == 0) {
        middle = length / 2 - 1;
    }
    else {
        middle = (length - 1) / 2;
    }

    while (i <= middle) {
        mx_swap_char(&s[i], &s[length-1-i]);
        i++;
    }
}
