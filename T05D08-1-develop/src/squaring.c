#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
        return 0;
    }
    return 0;
}

int input(int *a, int *n) {
    char ch;
    int var = scanf("%d%c", n, &ch);
    if (*n < 0 || var != 2 || ch != '\n') {
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &ch) != 2 || (p - a == *n - 1 && ch != '\n')) {
            return 1;
        }
    }
    return 0;
}
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}
