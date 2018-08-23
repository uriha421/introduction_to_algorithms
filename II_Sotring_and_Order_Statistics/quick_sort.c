// C program for a quick-sort algorithm.
// input: an integer array such as 1 3 4 2 9 7.
// output: a sorted array, 1 2 3 4 7 9.
#include "stdio.h"
#include "stdlib.h"

// quick_sort sorts a[p...r] and returns it.
void quick_sort(int a[], int p, int r);
// partition returns a key that is not more than all elements in a[p...key-1]
// and is not less than all elements in a[key+1...r].
int partition(int a[], int p, int r);
// exchange exchanges a[p] and a[q].
void exchange(int a[], int p, int q);

int main (int argc, char *argv[]) {

  // a receives command-line arguments.
  int a[argc - 1];
  for (int n = 0; n < argc - 1; n++) {
    a[n] = atoi(argv[n + 1]);
  }

  // quick-sort algorithm.
  quick_sort(a, 0, argc - 2);

  // shows the sorted array.
  for (int n = 0; n < argc - 1; n++) {
    printf("%d ", a[n]);
  }
}

void quick_sort(int a[], int p, int r) {
  if (p < r) {
    int q = partition(a, p, r); // divide a[p...r] at partition(a, p, r).
    quick_sort(a, p, q - 1); // conquer the divided problem.
    quick_sort(a, q + 1, r); // conquer the divided problem.
  }
}

int partition(int a[], int p, int r) {
  int right_edge = p - 1;
  int tmp;

  for (int i = p; i < r; i++) {
    if (a[i] < a[r]) {
      right_edge += 1;
      exchange(a, right_edge, i);
    }
  }

  exchange(a, right_edge + 1, r);

  return right_edge + 1;
}

void exchange(int a[], int p, int q) {
  int tmp = a[p];
  a[p] = a[q];
  a[q] = tmp;
}
