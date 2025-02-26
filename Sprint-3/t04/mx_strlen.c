int mx_strlen(const char *s) {
    int i = 0;
    int sum = 0;
    char c = s[0];

    while (c != '\0') {
        sum++;
        c = s[++i];
    }

    return sum;
}
