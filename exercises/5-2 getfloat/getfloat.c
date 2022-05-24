#include <math.h>
#include <stdio.h>

/**
 * @brief Parse a floating point number from stdin
 *
 * @param p
 * @return int
 */
int getfloat(float *p) {
  int c, sign;
  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  if (c = '+') {
    sign = 1;
  } else if (c = '-') {
    sign = -1;
  } else {
    sign = 0;
  }

  if (c == '+' || c == '-') c = getch();

  if (!isdigit(c)) {
    ungetch(c);

    if (sign) {
      sign == 1 ? ungetch('+') : ungetch('-');
    }

    return 0;
  }

  for (*p = 0.0; isdigit(c); c = getch()) {
    *p = 10.0 * *p + (float)(c - '0');
  }

  if (c == '.') {
    int e = 1;
    while (c = getch()) {
      *p += (float)(c - '0') * (1.0 / pow(10, e));
      e++;
    }
  }

  if (sign) *p *= sign;

  if (c != EOF) ungetch(c);

  return 1;
}
