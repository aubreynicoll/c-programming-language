/* This program attempts to remove all comments from C source code. It makes no
 * attempt at formatting the resulting code. */

#include <stdio.h>

int main() {
  int prev_c, curr_c;
  prev_c = '\0';
  while ((curr_c = getchar()) != EOF) {
    if (prev_c == '/' && curr_c == '/') {
      // handle line comment
      while ((curr_c = getchar()) != '\n')
        ;
    } else if (prev_c == '/' && curr_c == '*') {
      // handle block comment
      while ((curr_c = getchar()) != '/' || prev_c != '*') {
        prev_c = curr_c;
      }
      curr_c = getchar();
    } else {
      // print char
      prev_c != '\0' && putchar(prev_c);
    }
    prev_c = curr_c;
  }
  // handle last char
  putchar(prev_c);

  return 0;
}
