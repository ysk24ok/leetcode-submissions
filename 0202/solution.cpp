#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    int r;
    int next_n = 0;
    while (n != 1 && n != 7) {
      if (n / 10 == 0) return false;
      next_n = 0;
      while (n != 0) {
        r = n % 10;
        next_n += r * r;
        n /= 10;
      }
      n = next_n;
    }
    return true;
  }
};

int main() {
  Solution sol;
  assert(sol.isHappy(19));
  assert(!sol.isHappy(0));
  assert(sol.isHappy(1));
  assert(!sol.isHappy(2));
  assert(!sol.isHappy(3));
  assert(!sol.isHappy(4));
  assert(!sol.isHappy(5));
  assert(!sol.isHappy(6));
  assert(sol.isHappy(7));
  assert(!sol.isHappy(8));
  assert(!sol.isHappy(9));
}
