int mx_strlen(const char *s);

char *mx_strcat(char *s1, const char *s2) {
    int length_1 = mx_strlen((const char*)s1);
    int length_2 = mx_strlen(s2);
    int i = 0;

    for (i = 0; i < length_2; i++) {
        s1[length_1 + i] = s2[i];
    }

    s1[length_1 + length_2] = '\0';

    return s1;
}
