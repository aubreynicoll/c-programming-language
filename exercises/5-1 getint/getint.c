#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch())) /* skip white space */
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it is not a number */
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

  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }

  if (sign) *pn *= sign;

  if (c != EOF) ungetch(c);

  return c;
}
