void mx_sort_arr_int(int *arr, int size) {
    int i = 0;
    int j = 1;
    int help = 0;

    for (i = 0; i < size; ++i) {
        for (j = 1; j < size; ++j) {
            if (arr[j - 1] > arr[j]) {
                help = arr[j - 1];

                arr[j - 1] = arr[j];
                arr[j] = help;
            }
        }
    }
}
