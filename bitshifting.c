#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Bitshifting:\n");
  printf("%d\n", 1 << 0);
  // 1 << 0 = 1
  printf("%d\n", 1 << 1);
  // 1 << 1 = 2
  printf("%d\n", 1 << 2);
  // 1 << 2 = 4
  printf("%d\n", 1 << 3);
  // 1 << 3 = 8
  printf("%d\n", 1 << 4);
  // 1 << 4 = 16
  return EXIT_SUCCESS;
}