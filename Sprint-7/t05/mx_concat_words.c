#include <stddef.h>

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char *s1, const char *s2);
char *mx_strjoin(const char *s1, const char *s2);
void mx_strdel(char **str);

char *mx_concat_words(char **words) {
    int length = 0;
    int i = 0;
    char *newstr;
    char *temp;

    if (!words || !words[0]) {
        return NULL;
    }

    for (i = 0; words[i] != NULL; i++) {
        length += mx_strlen(words[i]) + 1;
    }

    newstr = mx_strnew(length - 1);

    if (!newstr) {
        return NULL;
    }

    newstr = mx_strdup(words[0]);

    for (i = 1; words[i] != NULL; i++) {
        temp = mx_strjoin(newstr, " ");

        mx_strdel(&newstr);

        newstr = mx_strjoin(temp, words[i]);

        mx_strdel(&temp);
    }

    return newstr;
}
