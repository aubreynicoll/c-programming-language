#include <stdio.h>

int main() {
  double c, f;
  double min, max, step;

  min = 0;
  max = 100;
  step = 1;

  c = min;

  printf("%3c\t%5c\n", 'c', 'f');
  while (c <= max) {
    f = c * (9.0 / 5.0) + 32;
    printf("%3.0f\t%5.1f\n", c, f);
    c += step;
  }

  return 0;
}
