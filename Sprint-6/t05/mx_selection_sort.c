int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);

int mx_selection_sort(char **arr, int size) {
    int count = 0;
    int i = 0;
    int min = 0;
    int len1 = 0;
    int len2 = 0;
    char *temp = "";

    for (i = 0; i < size - 1; i++) {
        min = i;

        for (int j = i + 1; j < size; j++) {
            len1 = mx_strlen(arr[j]);
            len2 = mx_strlen(arr[min]);

            if (len1 < len2
                || (len1 == len2 && mx_strcmp(arr[j], arr[min]) < 0)) {
                min = j;
            }
        }

        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            count++;
        }
    }

    return count;
}
