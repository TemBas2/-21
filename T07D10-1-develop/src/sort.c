#include <stdio.h>
#include <stdlib.h>
#define N 10

int input(int *a, int len);
void print(int *a, int len);
void sort(int *a, int len);

int main() {
    int len;
    char pop1;
    int *pup;
    if (scanf("%d%c", &len, &pop1) == 2 && pop1 == '\n' && len <= N && len > 0 && (int)len == len) {
        pup = ((int *)malloc(sizeof(int) * len));
        if (input(pup, len) == 1) {
            sort(pup, len);
            print(pup, len);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
        return 0;
    }
    free(pup);
    return 0;
}

int input(int *a, int len) {
    char pop;
    int gug = 0;
    for (int i = 0; i < len; i++) {
        int x = scanf("%d%c", &a[i], &pop);
        gug++;
        if (x == 0 || (i == len - 1 && pop != '\n')) {
            return 0;
        }
    }
    if (gug != len) {
        return 0;
    }
    return 1;
}

void print(int *a, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
}
void sort(int *a, int len) {
    int g;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (a[i] > a[j]) {
                g = a[i];
                a[i] = a[j];
                a[j] = g;
            }
        }
    }
}
