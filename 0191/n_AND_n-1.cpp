#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
      n &= n-1;
      count++;
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
