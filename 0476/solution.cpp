#include <cmath>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int findComplement(int num) {
    int ret = 0;
    int digit = 31;
    bool ok = false;
    while (digit >= 0) {
      bool reverse = false;
      if (num >= pow(2, digit)) {
        num -= pow(2, digit);
        ok = true;
        reverse = true;
      }
      if (ok && !reverse) {
        ret += 1;
      }
      digit--;
      ret <<= 1;
    }
    return ret >> 1;
  }
};

int main() {
  Solution sol;
  // 5: 101
  // 2: 010
  ExpectEqual(2, sol.findComplement(5));
  // 1: 1
  // 0: 0
  ExpectEqual(0, sol.findComplement(1));
  // 2: 10
  // 1: 01
  ExpectEqual(1, sol.findComplement(2));
}
