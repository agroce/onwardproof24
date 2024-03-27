#include <assert.h>

int nondet_int();

unsigned int binsearch(int* a, int key, unsigned int size, int* found) {
  unsigned int low = 0;
  unsigned int high = size - 1;
  
  while (low <= high) {
    unsigned int mid = (low + high) / 2;
    int midVal = a[mid];

    if (midVal < key)
      low = mid + 1;
    else if (midVal > key)
      high = mid - 1;
    else {
      (*found) = 1;
      return mid; // key found
    }
  }
  (*found) = 0;
  return 0;  // key not found.
}

#define SIZE 2

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

  int found = 0;
  unsigned int r = binsearch(a, k, SIZE, &found);
  if (found) {
    assert(a[r] == k);
  } else {
    
  }
}
