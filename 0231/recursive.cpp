#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n == 1) return true;
    else if (n == 0 || n % 2 == 1) return false;
    else return isPowerOfTwo(n / 2);
  }
};

int main() {
  Solution sol;
  assert(!sol.isPowerOfTwo(0));
  assert(sol.isPowerOfTwo(1));
  assert(sol.isPowerOfTwo(2));
  assert(!sol.isPowerOfTwo(3));
  assert(sol.isPowerOfTwo(4));
  assert(!sol.isPowerOfTwo(5));
  assert(!sol.isPowerOfTwo(6));
  assert(!sol.isPowerOfTwo(7));
  assert(sol.isPowerOfTwo(8));
}
