void mx_arr_rotate(int *arr, int size, int shift) {
    int replace[size];
    int i = 0;

    if (!arr || size <= 0) {
        return;
    }

    shift = shift % size;

    if (shift == 0) {
        return;
    }

    if (shift > 0) {
        for (i = 0; i < shift; i++) {
            replace[i] = arr[size - shift + i];
        }
        for (i = 0; i < size - shift; i++) {
            replace[shift + i] = arr[i];
        }
    }

    else {
        shift = -shift;

        for (i = 0; i < size - shift; i++) {
            replace[i] = arr[i + shift];
        }
        for (i = 0; i < shift; i++) {
            replace[size - shift + i] = arr[i];
        }
    }

    for (i = 0; i < size; i++) {
        arr[i] = replace[i];
    }
}
