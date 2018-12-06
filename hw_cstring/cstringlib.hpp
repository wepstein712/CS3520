#ifndef CSTRINGLIB_H
#define CSTRINGLIB_H

namespace str {
  typedef unsigned long size_t;

  size_t strlen(const char *str);
  char *strncpy(char *destination, const char *source, size_t num);
  char *strncat(char *destination, const char *source, size_t num);
  int strcmp(const char *str1, const char *str2);
  const char *strchr(const char *str, int character);
  const char *strrchr(const char *str, int character);
  const char *strstr(const char *str1, const char *str2);
  size_t strspn(const char *str1, const char *str2);
  size_t strcspn(const char *str1, const char *str2);
  char *strtok(char * str, const char * delimiters);
}

#endif
