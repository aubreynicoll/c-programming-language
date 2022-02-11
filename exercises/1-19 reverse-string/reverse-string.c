#include <stdio.h>

void reverse(char s[]);
size_t len(char s[]);

int main() {
  char string[] = "hello";

  printf("length: %ld\n", len(string));

  printf("%s\n", string);
  reverse(string);
  printf("%s\n", string);

  return 0;
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

size_t len(char s[]) {
  size_t len;
  for (len = 0; s[len] != '\0'; len++)
    ;
  return len;
}
