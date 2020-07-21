#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned int a, b, c;

  a = 1; // 0001
  b = 2; // 0010
  c = a | b;
  /*
  0001
  0010
  ----
  0011 -> 3
  */
  printf("c = a | b -> c=%d\n", c);

  a = a | b;
  /*
  0001
  0010
  ----
  0011 -> 3
  */

  // To write it a bit shorter, use this Syntax

  a |= b;

  /*
   0011
   0010
   ----
   0011 -> 3
   */

  printf("a |= b -> a=%d\n", a);

  return EXIT_SUCCESS;
}