int binsearch(int* a, int key, int size) {
  int low = 0;
  int high = size - 1;
  
  while (low < high) {
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

#define MAX_SIZE 10

int main () {
  int a[MAX_SIZE];
  int SIZE = nondet_int();
  __CPROVER_assume(SIZE > 0);
  __CPROVER_assume(SIZE <= MAX_SIZE);
  int k = nondet_int();
  int present = 0;
  for (int i = 0; i < SIZE; i++) {
    a[i] = nondet_int();
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
