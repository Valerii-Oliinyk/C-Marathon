int mx_count_words(const char *str, char delimiter) {
    int length = 0;
    int words = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] == delimiter) {
            if (length > 0) {
                words = words + 1;
                length = 0;
            }
        }
        else {
            length = length + 1;
        }

        i = i +1;
    }

    if (length > 0) {
        words = words + 1;
    }

    return words;
}
