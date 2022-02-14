#include <stdio.h>

int bitcount(unsigned x);

int main() {
  printf("%d\n", bitcount(255));
  printf("%d\n", bitcount(1));
  printf("%d\n", bitcount(0));
  return 0;
}

int bitcount(unsigned x) {
  if (!x) return 0;
  int bits = 1;
  while ((x &= x - 1)) bits++;
  return bits;
}
