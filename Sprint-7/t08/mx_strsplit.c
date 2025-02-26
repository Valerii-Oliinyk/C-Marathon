#include <stddef.h>
#include <stdlib.h>

int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);

char **mx_strsplit(char const *s, char c) {
    int words_count = 0;
    char **words = NULL;
    int i = 0;
    int word_index = 0;
    int start = 0;
    int len = 0;

    if (!s) return (char **)NULL;

    words_count = mx_count_words(s, c);

    if (words_count == 0) return (char **)NULL;

    words = (char **)malloc((words_count + 1) * sizeof(char *));

    if (!words) return (char **)NULL;

    while (s[i]) {
        while (s[i] == c) i++;

        if (s[i] != '\0') {
            start = i;

            while (s[i] && s[i] != c) i++;

            len = i - start;
            words[word_index] = mx_strnew(len);

            if (!words[word_index]) {
                for (int j = 0; j < word_index; j++) {
                    mx_strdel(&words[j]);
                }
                free(words);

                return (char **)NULL;
            }

            mx_strncpy(words[word_index], &s[start], len);

            word_index++;
        }
    }
    words[word_index] = NULL;

    return words;
}
