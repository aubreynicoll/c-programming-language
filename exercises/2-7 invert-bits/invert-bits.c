#include <stdio.h>

int invert(int x, int p, int n);

int main() {
  printf("%d\n", invert(15, 1, 2));
  printf("%d\n", invert(24212, 4, 4));
  printf("%d\n", invert(0, 0, 4));
  return 0;
}

int invert(int x, int p, int n) {
  int mask = ~(~0 << n) << p;
  return x ^ mask;
}
