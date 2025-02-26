void mx_swap_char(char *s1, char *s2) {
    int help = 0;

    help = *s1;
    *s1 = *s2;
    *s2 = help;
}
