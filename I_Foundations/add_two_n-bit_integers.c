// C program of adding two n-bit integers
// input: an integer n and two n-bit integers, such as 5 1 1 0 1 0 1 1 1 0 0
// output: a (n+1)-bit integer, 1 1 0 1 1 0
#include "stdio.h"
#include "stdlib.h"

int main ( int argc, char *argv[] ) {

  // a and b receive command-line arguments.
  // a = [1, 1, 0, 1, 0]
  // b = [1, 1, 1, 0, 0]
  int n = atoi(argv[1]);
  int a[n], b[n];
  for (int m = 0; m < n; m++) {
    a[m] = atoi(argv[m + 2]);
    b[m] = atoi(argv[m + 2 + n]);
  }

  // adding a and b
  int c[n + 1];
  c[n] = 0;
  int k;
  for (int m = n; m > 0; m--) {
    k = a[m - 1] + b[m - 1] + c[m]; // add (n-m+1)-digit of a and b
    // if in the previous iteration there is not an increase in digit, then c[m] = 0
    // if in the previous iteration there is an increase in digit, then c[m] = 1
    if (k < 2) { // if not increase in digit
      c[m] = k;
      c[m - 1] = 0; // not increase in digit
    } else { // if increase in digit
      c[m] = k - 2;
      c[m - 1] = 1; // increase in digit
    }
  }

  // shows the (n+1)-bit integer.
  for (int m = 0; m < n + 1; m++) {
    printf("%d ", c[m]);
  }
}
