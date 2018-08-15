// C program for finding when you should buy and sell an asset.
// input: an integer array such as 10 14 15 7 8 10 11 12 5 6 10 11 8,
// which means time series of the price of the asset.
// output: when you should buy and sell the asset, and your profit: 9 12 6,
// which means you should buy an asset at 9 and sell it at 12.
// Then you get the difference, 6.
#include "stdio.h"
#include "stdlib.h"

void max_crossing_subarray(int array[], int first, int last, int returns[3]);
// max_crossing_subarray receives an array and its indices, first and last.
// It returns two indices i and j, and the summation of a[i-1...j-1]
// such that middle := (first + last) / 2 in (i, i+1, ..., j-1, j)
// and the summation is the maximum of all.

void maximum_subarray(int array[], int first, int last , int returns[3]);
// maximum_subarray receives an array and its indices, first and last.
// It returns two indices i and j, and the summation of a[i-1...j-1]
// such that the summation is the maximum of all.

int main (int argc, char *argv[]) {

  // array receives command-line arguments,
  // and takes them as the difference.
  int array[argc - 2];
  for (int n = 0; n < argc - 2; n++) {
    array[n] = atoi(argv[n + 2]) - atoi(argv[n + 1]);
  }

  // maximum_subarray_algorithm.
  int returns[3] = {0, 0, 0};
  maximum_subarray(array, 1, argc - 2, returns);

  // shows the output.
  printf("you should buy the asset at %d and sell it at %d, then you can get %d", returns[0], returns[1] + 1, returns[2]);
}

void max_crossing_subarray(int array[], int first, int last, int returns[3]) {
  int middle = (first + last) / 2;
  int sum, max_left, max_right;

  // calculate the sum of the left and the right in the array
  // and add the maximum of the left sum and the maximum of the right sum.
  // then get the maximum.
  // e.g. (3 -2 1 5 -4 3 2 -2) -> the maximum of the left sum = 5 + 1 - 2 + 3 = 7
  // the maximum of the right sum = -4 + 3 + 2 = 1
  // then this function returns 7 + 1 = 8.

  // calculate the maximum of the left sum.
  sum = 0;
  max_left = 0;
  for (int n = middle - 1; n > first - 2; n--) {
    sum = sum + array[n];
    if (sum > max_left) {
      max_left = sum;
      returns[0] = n + 1;
    }
  }

  // calculate the maximum of the right sum.
  sum = 0;
  max_right = 0;
  for (int n = middle; n < last; n++) {
    sum = sum + array[n];
    if (sum > max_right) {
      max_right = sum;
      returns[1] = n + 1;
    }
  }

  returns[2] = max_left + max_right;

}

void maximum_subarray(int array[], int first, int last , int returns[3]) {

  if (first == last) {
      returns[0] = first + 1;
      returns[1] = last + 1;
      returns[2] = array[first - 1];
  } else { // if first < last
    int middle = (first + last) / 2;
    int max_returns[3];

    // calculate the maximum of the left sum,
    // e.g. (-1 5 -3 6 -3 5 5 -9 -3 1) --> 5 - 3 + 6 = 8
    // the maximum of the right sum, --> 5 + 5 = 10
    // and the maximum of the cross sum (see max_crossing_subarray()) --> 15
    // then this function returns 15

    maximum_subarray(array, first, middle, returns);
    for (int i = 0; i < 3; i++) {
      max_returns[i] = returns[i];
    }
    maximum_subarray(array, middle + 1, last, returns);
    if (max_returns[2] < returns[2]) {
      for (int i = 0; i < 3; i++) {
        max_returns[i] = returns[i];
      }
    }
    max_crossing_subarray(array, first, last, returns);
    if (max_returns[2] < returns[2]) {
      for (int i = 0; i < 3; i++) {
        max_returns[i] = returns[i];
      }
    }

    for (int i = 0; i < 3; i++) {
      returns[i] = max_returns[i];
    }
  }

}
