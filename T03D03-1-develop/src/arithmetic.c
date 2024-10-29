#include <stdio.h>

int main() {
  float a, b;
  int summa, minus, umnojenie, delenie;

  scanf("%f %f", &a, &b);

  if ((int)a != a) {
    printf("Первое число не целое.\n");
    return 1;
  }

  if ((int)b != b) {
    printf("Второе число не целое.\n");
    return 1;
  }
  summa = (int)a + (int)b;
  minus = (int)a - (int)b;
  umnojenie = (int)a * (int)b;

  if (b == 0) {
    printf("%d %d %d n/a\n", summa, minus, umnojenie);
  } else {
    delenie = (int)a / (int)b;
    printf("%d %d %d %d\n", summa, minus, umnojenie, delenie);
  }

  return 0;
}
