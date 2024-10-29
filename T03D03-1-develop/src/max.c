#include <stdio.h>

int func(int a, int b) {
  int max = b;
  if (a > b)
    max = a;
  return max;
}
int main() {
  float a, b;
  int m;
  scanf("%f %f", &a, &b);

  if ((int)a != a) {
    printf("n/a\n");
    return 1;
  }

  if ((int)b != b) {
    printf("n/a\n");
    return 1;
  }
  m = func(a, b);
  printf("%d", m);
}
