#include <stdio.h>

int includes(char s[], char c);
int find_any(char s[], char any[]);

int main() {
  printf("%d\n", find_any("hello world!", "hw"));
  printf("%d\n", find_any("hello world!", "de"));
  printf("%d\n", find_any("hello world!", "!"));
  printf("%d\n", find_any("hello world!", "xyz"));
  return 0;
}

int includes(char s[], char c) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == c) return 1;
  }
  return 0;
};

int find_any(char s[], char any[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (includes(any, s[i])) return i;
  }
  return -1;
}
