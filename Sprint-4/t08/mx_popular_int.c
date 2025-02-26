int mx_popular_int(const int *arr, int size) {
    int answer = 0;
    int freq = 0;
    int current = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < size; i++) {

        for (j = 0; j < size; j++) {
            if (arr[i] == arr[j])
                current++;
        }

        if (current > freq) {
            answer = arr[i];
            freq = current;
        }
    }

    return answer;
}
