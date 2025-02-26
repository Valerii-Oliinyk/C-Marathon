void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strlen(const char *s);

int main(int argc, char *argv[]) {
    int i = 1;

    if (argc < 2) {
        return 0;
    }

    while (i < argc) {
        mx_printstr(argv[i]);
        mx_printchar('\n');

        i = i + 1;
    }
}
