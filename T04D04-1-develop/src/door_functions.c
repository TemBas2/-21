#include <math.h>
#include <stdio.h>

#define PI 3.1415927

double verzier(double x) {
    if (x == 0) {
        return 1;

    } else {
        return 1 / (1 + x * x);
    }
}

double lemniscata(double x) {
    if (x > 0 && x < 1) {
        return sqrt(1 - x * x);

    } else {
        return -1;
    }
}

double hyperbola(double x) {
    if (x != 0) {
        return 1 / (x * x);

    } else {
        return -1;
    }
}

int main() {
    for (int i = 0; i <= 41; i++) {
        double x = -PI + i * (2 * PI) / 41;

        printf("%.7lf | %.7lf | ", x, verzier(x));

        if (lemniscata(x) != -1) {
            printf("%.7lf | ", lemniscata(x));

        } else {
            printf("- | ");
        }

        if (hyperbola(x) != -1) {
            printf("%.7lf\n", hyperbola(x));

        } else {
            printf("-\n");
        }
    }

    return 0;
}
