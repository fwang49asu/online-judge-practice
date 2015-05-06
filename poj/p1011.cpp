#include <iostream>
#include <cstdlib>

using namespace std;

int size;
int sticks[64];
bool used[64];
int sum;
int length;

int reverse_cmp_int(const void *ap, const void *bp) {
  const int *a = static_cast<const int*>(ap);
  const int *b = static_cast<const int*>(bp);
  return (*b) - (*a);
}

int next(int index) {
  int i = index;
  for(; i<size && used[i]; ++i);
  return i;
}

bool can_fit(int times, int index, int total) {
  if(times == (sum / length)) {
    return true;
  }
  for(int start = next(index); start < size; start = next(start+1)) {
    if(sticks[start] == total) {
      used[start] = true;
      // test for the next
      if(can_fit(times+1, 0, length)) {
        return true;
      }
      used[start] = false;
      return false;
    } else if(sticks[start] < total) {
      used[start] = true;
      if(can_fit(times, start + 1, total - sticks[start])) {
        return true;
      }
      used[start] = false;
      if(total == length) {
        return false;
      }
      while(sticks[start] == sticks[start + 1]) {
        ++start;
      }
    } else if(total == length) {
      return false;
    }
  }

  return false;
}

int min_length() {
  int start = sticks[0];
  sum = 0;
  for(int i=0; i<size; ++i) {
    sum += sticks[i];
  }

  for(int i=start; i<sum; ++i) {
    if((sum % i) != 0) {
      continue;
    }
    for(int k=0; k<size; ++k) {
      used[k] = false;
    }
    length = i;
    if(can_fit(1, 0, length)) {
      return i;
    }
  }
  return sum;
}

int main(int argc, char* argv[]) {
  while(cin >> size) {
    if(size == 0) {
      break;
    }
    for(int i=0; i<size; ++i) {
      cin >> sticks[i];
    }
    qsort(sticks, size, sizeof(int), reverse_cmp_int);
    
    cout << min_length() << endl;
  }

  return 0;
}
