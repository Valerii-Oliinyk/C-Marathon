int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int low = 0;
    int high = size - 1;
    int mid = 0;
    int cmp = 0;
    *count = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        (*count) = (*count) + 1;
        cmp = mx_strcmp(arr[mid], s);

        if (cmp == 0) {
            return mid;
        }
        else if (cmp > 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    *count = 0;

    return -1;
}
