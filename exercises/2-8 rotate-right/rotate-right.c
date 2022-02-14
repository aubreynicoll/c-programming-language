#include <stdio.h>

int rotr(int x, int n);

int main() {
  printf("%d\n", rotr(1, 0));
  printf("%d\n", rotr(1, 1));
  printf("%d\n", rotr(5, 1));
  printf("%d\n", rotr(5, 32));
  printf("%d\n", rotr(5, 31));
  printf("%d\n", rotr(5, 64));
  return 0;
}

int rotr(int x, int n) {
  int lost_bits = (x & ~(~0 << n)) << ((sizeof x) * 8 - n);
  x = x >> n;
  return x + lost_bits;
}
