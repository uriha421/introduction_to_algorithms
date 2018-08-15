// C program for finding when you should buy and sell an asset.
// input: an integer array such as 10 14 15 7 8 10 11 12 5 6 10 11 8,
// which means time series of the price of the asset.
// output: when you should buy and sell the asset, and your profit: 9 12 6,
// which means you should buy an asset at 9 and sell it at 12.
// Then you get the difference, 6.
#include "stdio.h"
#include "stdlib.h"

int main (int argc, char *argv[]) {

  // array receives command-line arguments
  int array[argc - 1];
  for (int n = 0; n < argc - 1; n++) {
    array[n] = atoi(argv[n + 1]);
  }

  // calculate all patterns
  int i, j, tmp;
  int max = -65535;
  for (int n = 0; n < argc - 1; n++) {
    for (int m = n + 1; m < argc - 1; m++) {
      tmp = array[m] - array[n];
      if (max < tmp) {
        max = tmp;
        i = n;
        j = m;
      }
    }
  }

  // shows the output.
  printf("you should buy the asset at %d and sell it at %d, then you can get %d", i + 1, j + 1, max);
}
