#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    uint32_t mask = 1;
    for (int i = 0; i < 32; i++) {
      if (mask & n) count++;
      mask <<= 1;
    }
    return count;
  }
};

int main() {
  Solution sol;
  uint32_t i;

  i = 0b00000000000000000000000000000001;
  assert(sol.hammingWeight(i) == 1);

  i = 0b00000000000000000000000000001011;
  assert(sol.hammingWeight(i) == 3);

  i = 0b00000000000000000000000010000000;
  assert(sol.hammingWeight(i) == 1);

  i = 0b11111111111111111111111111111101;
  assert(sol.hammingWeight(i) == 31);
}
