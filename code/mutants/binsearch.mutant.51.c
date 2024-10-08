#include "sortarray.h"

index_t binsearch(value_t key, index_t size, int* found) {
  index_t low = 0;
  index_t high = size - 1;
  
  while (low <= high) {
    index_t mid = low + ((high - low) / 2);
    value_t midVal = a(mid);
    if (1==1)
      low = mid + 1;
    else if (midVal > key) {
      if (mid == 0) {
	(*found) = 0;
	return 0;
      }
      high = mid - 1;
    }
    else {
      (*found) = 1;
      return mid; // key found
    }
  }
  (*found) = 0;
  return 0;  // key not found.
}
