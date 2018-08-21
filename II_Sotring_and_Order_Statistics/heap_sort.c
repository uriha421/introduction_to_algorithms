// C program for an heap-sort algorithm.
// input: an integer array such as 1 3 4 2 9 7.
// output: a sorted array, 1 2 3 4 7 9.
#include "stdio.h"
#include "stdlib.h"

int parent(int i);
int left(int i);
int right(int i);
void max_heaptify(int a[], int i, int heap_size);
void build_max_heap(int a[], int heap_size);
void heap_sort(int a[], int heap_size);

int main (int argc, char *argv[]) {

  // a receives command-line arguments.
  int a[argc - 1];
  for (int n = 0; n < argc - 1; n++) {
    a[n] = atoi(argv[n + 1]);
  }

  int heap_size = argc - 1;

  // heap-sort algorithm.
  heap_sort(a, heap_size);

  // shows the sorted array.
  for (int n = 0; n < argc - 1; n++) {
    printf("%d ", a[n]);
  }
}

int parent(int i) {
  return i / 2;
}

int left(int i) {
  return 2 * i;
}

int right(int i) {
  return 2 * i + 1;
}

void max_heaptify(int a[], int i, int heap_size) {
  int l = left(i);
  int r = right(i);
  int max, tmp;

  if (l <= heap_size && a[l - 1] > a[i - 1]) {
    max = l;
  } else {
    max = i;
  }
  if (r <= heap_size && a[r - 1] > a[max - 1]) {
    max = r;
  }
  if (max != i) {
    tmp = a[max - 1];
    a[max - 1] = a[i - 1];
    a[i - 1] = tmp;
    max_heaptify(a, max, heap_size);
  }
}

void build_max_heap(int a[], int heap_size) {
  for (int i = heap_size / 2; i > 0; i--) {
    max_heaptify(a, i, heap_size);
  }
}

void heap_sort(int a[], int heap_size) {
  int tmp;

  build_max_heap(a, heap_size);
  for (int i = heap_size; i > 0; i--) {
    tmp = a[0];
    a[0] = a[i - 1];
    a[i - 1] = tmp;

    heap_size -= 1;
    max_heaptify(a, 1, heap_size);
  }
}
