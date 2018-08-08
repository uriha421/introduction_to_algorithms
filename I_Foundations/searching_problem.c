// C program of searcing problem
// input: an integer array and an integer such as 4 3 2 5 1 5
// output: where the last integer is, 4
#include "stdio.h"
#include "stdlib.h"

int main ( int argc, char *argv[] ) {

  // a receives command-line arguments.
  int a[argc - 2];
  for (int n = 0; n < argc - 2; n++) {
    a[n] = atoi(argv[n + 1]);
  }

  // solves searcing problem.
  int n = 0;
  while (a[n] != atoi(argv[argc - 1]) && n < argc - 1) {
    n = n + 1;
  }

  printf("%d\n", n + 1);
}
