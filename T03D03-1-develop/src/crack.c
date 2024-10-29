#include <stdio.h>

int main() {

  float x, y;
  int cheaker;
  cheaker = scanf("%f%f", &x, &y);
  if (cheaker == 0) {
    printf("n/a \n");
  } else {
    if (x * x + y * y < 25) {
      printf("GOTCHA\n");
    } else {
      printf("MISS\n");
    }
  }
}
