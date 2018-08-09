// C program for an insertion-sort algorithm.
// input: an integer array such as 1 3 4 2 9 7.
// output: a sorted array, 1 2 3 4 7 9.
#include "stdio.h"
#include "stdlib.h"

int main ( int argc, char *argv[] ) {

  // a receives command-line arguments.
  int a[argc - 1];
  for (int n = 0; n < argc - 1; n++) {
    a[n] = atoi(argv[n + 1]);
  }

  // insertion-sort algorithm.
  int k, l;
  for (int n = 0; n < argc - 2; n++) {
    k = a[n];
    l = n;
    for (int m = n + 1; m < argc - 1; m++) {
      if (a[n] > a[m]) {
        k = a[m];
        l = m;
      }
    }
    a[l] = a[n];
    a[n] = k;
  }

  // shows the sorted array.
  for (int n = 0; n < argc - 1; n++) {
    printf("%d ", a[n]);
  }
}
