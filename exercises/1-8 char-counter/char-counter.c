#include <stdio.h>

int main() {
  unsigned long blanks, tabs, newlines;
  blanks = tabs = newlines = 0;

  int c;
  while ((c = getchar()) != EOF) {
    switch (c) {
      case ' ':
        blanks++;
        break;
      case '\t':
        tabs++;
        break;
      case '\n':
        newlines++;
        break;
      default:
        break;
    }
  }

  printf("blanks: %lu\n", blanks);
  printf("tabs: %lu\n", tabs);
  printf("newlines: %lu\n", newlines);

  return 0;
}
