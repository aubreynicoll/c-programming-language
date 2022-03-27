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

/* itob: convert n into a base b representation via s */
void itob(int n, char s[], int b) {
  int i, sign = n;

  i = 0;
  do {
    int temp = abs(n % b);
    if (temp < 10) {
      s[i++] = temp + '0';
    } else {
      s[i++] = temp + 'a' - 10;
    }
  } while (abs(n /= b) > 0);

  if (sign < 0) s[i++] = '-';

  s[i] = '\0';

  reverse(s);
};

int main() {
  char s[1024];
  // tests
  itob(INT_MIN, s, 10);
  printf("%s\n", s);
  return 0;
}