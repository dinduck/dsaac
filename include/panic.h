#include <stdlib.h>
#ifndef _PANIC_H
#include <stdio.h>
/* #define Error(x) printf("%s", x); */
void Error(const char *s) { printf("%s\n", s); }
void Panic(const char *s) {
  printf("%s\n", s);
  exit(1);
}
#endif // !DEBUG
