#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int result = 0;
        for(unsigned int i=1, lowMask = 2, highMask = (1 << 30); i<32; ++i, lowMask = (lowMask << 1), highMask = (highMask >> 1)) {
            if((n & lowMask)!= 0) {
                result |= highMask;
            }
        }
        if(n & 1) {
          result |= (1 << 31);
        }
        return result;
    }
};

int main() {
  unsigned int n = 1;
  Solution s;
  cout << s.reverseBits(n) << endl;
  return 0;
}
