#include <algorithm>
#include <deepstate/DeepState.hpp>

using namespace deepstate;

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

#define SIZE 1

TEST(Run, Bentley) {
  int a[SIZE];
  int k = DeepState_Int();
  //__CPROVER_assume(k > -SIZE);
  //__CPROVER_assume(k < SIZE);   
  int present = 0;
  for (int i = 0; i < SIZE; i++) {
    a[i] = DeepState_Int();
    LOG(TRACE) << "a[" << i << "] = " << a[i];
    if (a[i] == k) {
      present = 1;
    }
  }
  std::sort(std::begin(a), std::end(a));
  if (DeepState_Bool()) {
    present = 1;
    k = a[DeepState_IntInRange(0,SIZE-1)];
  }
    

  int r = binsearch(a, k, SIZE);
  if (r != -1) {
    assert(a[r] == k);
  } else {
    assert(!present);
  }
}
