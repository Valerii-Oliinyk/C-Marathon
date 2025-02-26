int mx_strcmp(const char *s1, const char *s2);

int mx_bubble_sort(char **arr, int size) {
    int i = 0;
    int j = 1;
    char *help = "";
    int count = 0;

    for (i = 0; i < size; ++i) {
        for (j = 1; j < size; ++j) {
            if (mx_strcmp(arr[j], arr[j - 1]) < 0) {
                help = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = help;

                count = count + 1;
            }
        }
    }

    return count;
}
