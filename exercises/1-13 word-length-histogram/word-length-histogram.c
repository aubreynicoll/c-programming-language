#include <stdio.h>

#define MAX_LENGTH 20

int main() {
  unsigned long count[MAX_LENGTH];
  for (int i = 0; i < MAX_LENGTH; i++) count[i] = 0;

  unsigned long curr_length = 0;

  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (curr_length > 0 && curr_length <= MAX_LENGTH) {
        count[curr_length - 1]++;
        curr_length = 0;
      }
    } else {
      curr_length++;
    }
  }

  for (int i = 0; i < MAX_LENGTH; i++) {
    printf("%2d: ", i + 1);
    for (int ii = 0; ii < count[i]; ii++) {
      printf("|");
    }
    printf("\n");
  }

  return 0;
}
