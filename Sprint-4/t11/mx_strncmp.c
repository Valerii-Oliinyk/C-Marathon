int mx_strncmp(const char *s1, const char *s2, int n) {
    while (*s1 && *s2 && *s1 == *s2 && n > 1) {
        s1++;
        s2++;
        n--;
    }

    return *s1 - *s2;
}

