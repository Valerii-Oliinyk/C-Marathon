double mx_pow(double n, unsigned int pow) {
    unsigned int i = 0;
    double result = 1.0;

    if (pow == 0) {
        return 1;
    }


    for (i = 0; i < pow; i++) {
        result = result * n;
    }

    return result;
}
