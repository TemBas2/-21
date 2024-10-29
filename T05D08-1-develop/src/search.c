#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n) {
    char pop;
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 0;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d%c", &a[i], &pop) != 2 || (i == *n - 1 && pop != '\n')) {
            return 0;
        }
    }

    return 1;
}

double mean(int *a, int n) {
    if (n == 0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    if (n == 0) {
        return 0;
    }
    double mean_v = mean(a, n);
    double sum_sq_diff = 0;
    for (int i = 0; i < n; i++) {
        sum_sq_diff += pow(a[i] - mean_v, 2);
    }
    return sum_sq_diff / n;
}

int search(int *a, int n) {
    double mean_v = mean(a, n);
    double variance_v = variance(a, n);
    double threshold = mean_v + 3 * sqrt(variance_v);

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean_v && a[i] <= threshold && a[i] != 0) {
            return a[i];
        }
    }
    return 0;
}

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        printf("n/a\n");
        return 1;
    }
    int result = search(data, n);
    printf("%d\n", result);
    return 0;
}
