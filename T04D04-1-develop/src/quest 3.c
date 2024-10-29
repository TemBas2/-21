#include <stdio.h>
int fibonacci(int N) {
    if (N == 1 || N == 2) return 1;
    return fibonacci(N - 1) + fibonacci(N - 2);
}
int main() {
    int N, m;
    int checkher;
    checkher = scanf("%d", &N);
    if (checkher == 0)

    {
        printf("n/a");
    } else {
        m = fibonacci(N);
        printf("%d", m);
        return 0;
    }
}
