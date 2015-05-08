#include <iostream>

using namespace std;

bool test(int n, int m) {
  int position;
  int rest = 2 * n;
  position = 0;
  while(rest > n) {
    position = (position + m -1)%rest;
    if(position < n) {
      return false;
    }
    --rest;
  }
  return true;
}

int min_solution(int n) {
  for(int result = n+1; ;result += n+1) {
    if(test(n, result)) {
      return result;
    }
    if(test(n, result+1)) {
      return result+1;
    }
  }
}

int main(int argc, char* argv[]) {
  int result[14];

  for(int i=0; i<14; ++i) {
    result[i] = 0;
  }
  
  int n;
  cin >> n;
  while(n != 0) {
    if(result[n] == 0) {
      result[n] = min_solution(n);
    }
    cout << result[n] << endl;
    cin >> n;
  }
  return 0;
}
