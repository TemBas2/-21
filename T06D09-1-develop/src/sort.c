#include <stdio.h>
#define N 10

int input(int *a);
void print(int *a);
void sort(int *a);

int main() {
    int pup[N];
    if (input(pup) == 1) {
        sort(pup);
        print(pup);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {
    char pop;
    for (int i = 0; i < 10; i++) {
        if (scanf("%d%c", &a[i], &pop) == 0 || (i == 9 && pop != '\n')) {
            return 0;
        }
    }
    return 1;
}

void print(int *a) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
}
void sort(int *a) {
    int g;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (a[i] > a[j]) {
                g = a[i];
                a[i] = a[j];
                a[j] = g;
            }
        }
    }
}
