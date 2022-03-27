/* To answer the question posed by the text first, INT_MIN in a two's complement
 * machine has no positive counterpart: it simply overflows, because INT_MAX is
 * defined as 2^(w - 1) - 1, which is one less than a negated INT_MIN. Since the
 * value overflows by one, any negation of INT_MIN yields INT_MIN. This causes
 * problems later in the program when n is assumed to be positive. */

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

size_t len(char s[]) {
  size_t len;
  for (len = 0; s[len] != '\0'; len++)
    ;
  return len;
}

void reverse(char s[]) {
  int i, j, temp;
  i = -1;
  j = len(s);

  while (++i < --j) {
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
  }
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[]) {
  int i, sign = n;

  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while (abs(n /= 10) > 0);

  if (sign < 0) s[i++] = '-';
  s[i] = '\0';

  reverse(s);
}

int main() {
  char s[1000];
  // tests
  itoa(INT_MIN, s);
  printf("%s\n", s);
  itoa(123, s);
  printf("%s\n", s);
  itoa(-123, s);
  printf("%s\n", s);
  return 0;
}