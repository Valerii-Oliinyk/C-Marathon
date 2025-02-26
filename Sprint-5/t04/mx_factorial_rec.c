int mx_factorial_rec(int n) {
    if (n < 0) {
        return 0;
    }
    else if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return 1;
    }

    n = n * mx_factorial_rec(n - 1);

    if (n < 0) {
        return 0;
    }

    return n;
}
