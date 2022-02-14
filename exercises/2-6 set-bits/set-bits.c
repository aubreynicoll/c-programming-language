#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
  printf("%d\n", setbits(3, 2, 2, 3));
  printf("%d\n", setbits(567, 0, 3, 0));
  printf("%d\n", setbits(9876, 10, 5, 567));
  return 0;
}

int setbits(int x, int p, int n, int y) {
  y = (y & ~(~0 << n)) << p;
  x = x & ~(~(~0 << n) << p);
  return x + y;
}
