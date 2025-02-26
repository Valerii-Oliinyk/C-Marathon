int mx_strlen(const char *s);

int mx_insertion_sort(char **arr, int size) {
    int i = 1;
    int j = 0;
    char *help = "";
    int shifts = 0;

    for (i = 1; i < size; ++i) {
        j = i - 1;
        help = arr[i];

        while (j >= 0 && mx_strlen(arr[j]) > mx_strlen(help)) {
            arr[j + 1] = arr[j];
            j = j - 1;
            shifts = shifts + 1;
        }

        arr[j + 1] = help;
    }

    return shifts;
}
