#include <iostream>
#include <cstdlib>

using namespace std;

int reverse_cmp_int(const void *ap, const void *bp) {
  const int *a = static_cast<const int*>(ap);
  const int *b = static_cast<const int*>(bp);
  return (*b) - (*a);
}

int next(int size, int* sticks, bool* used, int index, int total) {
  if(index >= size) {
    return size;
  }
  int i = index;
  for(; i<size && (used[i] || (sticks[i] > total)); ++i);
  return i;
}

bool can_fit(int size, int* sticks, bool* used, int index, int total) {
  int cur = sticks[index];
  if(cur > total) {
    return false;
  }
  if(cur == total) {
    used[index] = true;
    return true;
  }
  used[index] = true;
  int next_total = total - cur;
  int i = next(size, sticks, used, index+1, next_total);
  for(; i<size; i = next(size, sticks, used, i+1, next_total)) {
    if(can_fit(size, sticks, used, i, next_total)) {
      return true;
    }
  }
  used[index] = false;
  return false;
}

bool can_total_fit(int size, int* sticks, bool* used, int total) {
  for(int i=0; i<size; i = next(size, sticks, used, i+1, total)) {
    if(!can_fit(size, sticks, used, i, total)) {
      for(int k=0; k<size; ++k) {
        used[k] = false;
      }
      return false;
    }
  }
  return true;
}

int min_length(int size, int* sticks, bool* used) {
  int start = sticks[0];
  // use sum as end
  int end = 0;
  for(int i=0; i<size; ++i) {
    end += sticks[i];
  }

  int result = start;
  for(; result <= end; ++result) {
    if(end % result != 0) {
      continue;
    }
    if(can_total_fit(size, sticks, used, result)) {
      break;
    }
  }

  return result;
}

int main(int argc, char* argv[]) {

  int size;
  int sticks[64];
  bool used[64];

  while(cin >> size) {
    if(size == 0) {
      break;
    }
    for(int i=0; i<size; ++i) {
      cin >> sticks[i];
      used[i] = false;
    }
    qsort(sticks, size, sizeof(int), reverse_cmp_int);
    
    cout << min_length(size, sticks, used) << endl;
  }

  return 0;
}
