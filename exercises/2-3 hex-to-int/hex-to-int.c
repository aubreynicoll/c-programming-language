#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int htoi(const char h[]);

int main() {
  // code
  printf("0: %d\n", htoi("0"));
  printf("0x0: %d\n", htoi("0x0"));
  printf("FF: %d\n", htoi("FF"));
  printf("0xFF: %d\n", htoi("0xFF"));
  printf("0xff: %d\n", htoi("0xff"));
  printf("0xDECAFBAD: %d\n", htoi("0xDECAFBAD"));
  printf("DECAFBAD: %d\n", htoi("DECAFBAD"));
  printf("DECAFXBAD: %d\n", htoi("DECAFXBAD"));  // expect to crash

  return 0;
}

int htoi(const char s[]) {
  int n = 0;
  int len = strlen(s);

  for (int i = len > 2 && tolower(s[1]) == 'x' ? 2 : 0; i < len; i++) {
    int c = tolower(s[i]);

    if (!(c >= '0' && c <= '9' || c >= 'a' && c <= 'f')) {
      fprintf(stderr,
              "ERROR: htoi expects a valid hexidecimal string, got \"%s\"\n",
              s);
      exit(1);
    }

    if (isdigit(c)) {
      n = 16 * n + (c - '0');
    } else {
      n = 16 * n + (c - 'a' + 10);
    }
  }

  return n;
}
