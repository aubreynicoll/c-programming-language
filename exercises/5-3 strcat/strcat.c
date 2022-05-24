#include "stdio.h"

void strcat(char *s, const char *t) {
  while (*s) s++;
  while (*s++ = *t++)
    ;
}

int main() {
  char a[50] = "hello, ";
  char b[50] = "world!";

  strcat(a, b);

  printf("%s\n", a);

  return 0;
}
