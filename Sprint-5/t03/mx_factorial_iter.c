int mx_factorial_iter(int n) {
    int pos = n - 1;

    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return 0;
    }

    while (pos > 1) {
        if (n * pos < 0) {
            return 0;
        }

        n = n * pos;
        pos = pos - 1;
    }

    return n;
}
