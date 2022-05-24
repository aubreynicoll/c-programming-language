#include "stdio.h"

size_t len(const char *s) {
  char *sp = s;
  while (*s++)
    ;
  return s - sp;
}

int strend(const char *s, const char *t) {
  size_t s_len, t_len;

  s_len = len(s);
  t_len = len(t);

  if (t_len > s_len) return 0;

  s += s_len - t_len;
  for (size_t i = 0; i < t_len; i++)
    if (*s++ != *t++) return 0;
  return 1;
}
