#include "stdio.h"

/**
 * @brief Copy n chars from one string to another.
 *
 * @param s
 * @param t
 * @param bytes
 */
void strncpy(char *s, const char *t, size_t n) {
  while (n--) {
    if (*t) {
      *s++ = *t++;
    } else {
      *s++ = '\0';
    }
  }
}

/**
 * @brief Append string t to string s.
 *
 * @param s
 * @param t
 * @param bytes
 */
void strncat(char *s, const char *t, size_t n) {
  while (*s) s++;
  while (n--) {
    *s++ = *t++;
  }
  *s = '\0';
}

/**
 * @brief Compare n bytes of string s and string t. Returns the result of s[n] -
 * t[n] or of the first unequal char.
 *
 * @param s
 * @param t
 * @param bytes
 * @return int
 */
int strncmp(const char *s, const char *t, size_t n) {
  while (n-- && *s++ == *t++)
    ;
  return *s - *t;
}
