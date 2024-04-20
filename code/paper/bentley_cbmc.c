#include <assert.h>

int nondet_int();

int binsearch(int* a, int key, int size) {
  int low = 0;
  int high = size - 1;
  
  while (low <= high) {
    int mid = (low + high) / 2;
    int midVal = a[mid];

    if (midVal < key)
      low = mid + 1;
    else if (midVal > key)
      high = mid - 1;
    else {
      return mid; // key found
    }
  }
  return -1;  // key not found.
}

#define SIZE 10

int main () {
  int a[SIZE];
  int k = nondet_int();
  __CPROVER_assume(k > -SIZE);
  __CPROVER_assume(k < SIZE);   
  int present = 0;
  for (int i = 0; i < SIZE; i++) {
    a[i] = nondet_int();
    __CPROVER_assume(a[i] > -SIZE);
    __CPROVER_assume(a[i] < SIZE); 
    if (i > 0) {
      __CPROVER_assume(a[i] >= a[i-1]);
    }
    if (a[i] == k) {
      present = 1;
    }
  }

  int r = binsearch(a, k, SIZE);
  if (r != -1) {
    assert(a[r] == k);
  } else {
    assert(!present);
  }
}
