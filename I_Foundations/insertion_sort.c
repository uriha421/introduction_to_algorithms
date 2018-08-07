// C program for an insertion-sort algorithm.
#include "stdio.h"
#include "stdlib.h"

int main ( int argc, char *argv[] ) {

  // a receives command-line arguments
  int a[argc - 1];
  for (int n = 0; n < argc - 1; n++) {
    a[n] = atoi(argv[n + 1]);
  }

  // insertion-sort algorithm
  int k, m;
  for (int n = 1; n < argc - 1; n++) {
    k = a[n];
    m = n - 1;
    while (k < a[m] && m >= 0) {
      a[m + 1] = a[m];
      a[m] = k;
      m = m - 1;
    }
  }

  // shows the sorted array.
  for (int n = 0; n < argc - 1; n++) {
    printf("%d\n", a[n]);
  }
}
