// C program for a heap-sort algorithm.
// input: an integer array such as 1 3 4 2 9 7.
// output: a sorted array, 1 2 3 4 7 9.
#include "stdio.h"
#include "stdlib.h"

// heap_sort receives an array to be sorted and its heap size,
// and returns sorted a[0...heap_size-1].
void heap_sort(int a[], int heap_size);
// build_max_heap returns a heap that meets max-heap-property,
// which means that the number of parents is not less than the two numbers of its children.
// That also means a[0] is not less than all elements in a[].
void build_max_heap(int a[], int heap_size);
// max_heaptify receives an array a[] and an index i.
// It sorts the array such that a[i] is not less than a[left(i)] and a[right(i)],
// and keeps max-heap-property.
void max_heaptify(int a[], int i, int heap_size);

int parent(int i); // returns the index of the parent node of node i.
int left(int i); // returns the index of the left node of node i.
int right(int i); // returns the index of the right node of node i.
void exchange(int a[], int p, int q); // exchanges a[p] and a[q].

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

void heap_sort(int a[], int heap_size) {
  int tmp;

  build_max_heap(a, heap_size);
  for (int i = heap_size; i > 0; i--) {
    exchange(a, 0, i - 1);

    heap_size -= 1;
    max_heaptify(a, 1, heap_size);
  }
}

void build_max_heap(int a[], int heap_size) {
  for (int i = heap_size / 2; i > 0; i--) {
    max_heaptify(a, i, heap_size);
  }
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
    exchange(a, i - 1, max - 1);
    max_heaptify(a, max, heap_size);
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

void exchange(int a[], int p, int q) {
  int tmp = a[p];
  a[p] = a[q];
  a[q] = tmp;
}
