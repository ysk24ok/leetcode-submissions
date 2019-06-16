#include <cassert>
#include <iostream>
#include <limits>

class Solution {
 public:
  int reverse(int x) {
    const int min = std::numeric_limits<int>::min();
    const int max = std::numeric_limits<int>::max();
    int ret = 0;
    while (true) {
      if (x == 0) {
        break;
      }
      int pop = x % 10;
      x /= 10;
      if (ret > max / 10 || ret < min / 10) {
        return 0;
      }
      ret *= 10;
      if (pop >= 0 && ret > max - pop) {
        return 0;
      }
      if (pop < 0 && ret < min - pop) {
        return 0;
      }
      ret += pop;
    }
    return ret;
  }
};


int main() {
  Solution* sol = new Solution();
  assert(sol->reverse(123) == 321);
  assert(sol->reverse(-123) == -321);
  assert(sol->reverse(120) == 21);
  assert(sol->reverse(1000000009) == 0);
  assert(sol->reverse(-1000000009) == 0);
  delete sol;
}
