// C program for an merge-sort algorithm.
// input: an integer array such as 1 3 4 2 9 7.
// output: a sorted array, 1 2 3 4 7 9.
#include "stdio.h"
#include "stdlib.h"

void merge( int a[], int p, int q, int r );
// merge receives:
// a: an integer array such that a[p-1 ... q-1] and a[q ... r-1] are sorted.
// p, q, r: each is an index of the array such that p < q <= r.
// merge returns the array a such that a[p-1 ... r-1] is sorted.

void merge_sort( int a[], int p, int r );
// merge_sort receives an integer array a, two index of the array, p and r.
// It returns a partially sorted array of a such that a[p-1 ... r-1] are sorted.

int main ( int argc, char *argv[] ) {

  // a receives command-line arguments.
  int a[argc - 1];
  for (int n = 0; n < argc - 1; n++) {
    a[n] = atoi(argv[n + 1]);
  }

  // merge-sort algorithm.
  merge_sort(a, 1, argc - 1);

  // shows the sorted array.
  for (int n = 0; n < argc - 1; n++) {
    printf("%d ", a[n]);
  }
}

void merge( int a[], int p, int q, int r ) {
  // set b = [a[p-1 ... q-1], 65535], and c = [a[q ... r-1], 65535].
  // and so n = b.length + 1, m = c.length + 1
  int n = q - p + 1;
  int m = r - q;
  int b[n + 1];
  int c[m + 1];
  for (int i = 0; i < n; i++) {
    b[i] = a[i + p - 1];
  }
  b[n] = 655;
  for (int i = 0; i < m; i++) {
    c[i] = a[i + q];
  }
  c[m] = 655;

  int i = 0;
  int j = 0;
  for (int k = p - 1; k < r; k++) {
    if (b[i] < c[j]) {
      a[k] = b[i];
      i++;
    } else {
      a[k] = c[j];
      j++;
    }
  }
}

void merge_sort( int a[], int p, int r ) {
  int q;
  if (p < r) {
    q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }
}
