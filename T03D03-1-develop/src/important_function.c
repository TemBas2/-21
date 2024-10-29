#include <math.h>
#include <stdio.h>

int main() {
  float x;
  int checkher;
  checkher = scanf("%f", &x);
  if (checkher == 0) {
    printf("n/a");
  } else {

    printf("%.1f", (7e-3 * pow(x, 4) +
                    ((22.8 * pow(x, (1 / 3)) - 1e3) * x + 3) / (x * x / 2) -
                    x * pow((10 + x), (2 / x)) - 1.01));
  }

  return 0;
}
