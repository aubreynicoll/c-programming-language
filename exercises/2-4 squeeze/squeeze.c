#include <stdio.h>

void squeeze(char s1[], char s2[]);
int includes(char s[], char c);

int main() {
  char s1[] = "hello world!";
  char s2[] = "lo!";
  squeeze(s1, s2);
  printf("%s\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j;

  for (i = j = 0; s1[j] != '\0'; j++) {
    if (!includes(s2, s1[j])) {
      s1[i++] = s1[j];
    }
  }
  s1[i] = '\0';
};

int includes(char s[], char c) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == c) return 1;
  }
  return 0;
};
