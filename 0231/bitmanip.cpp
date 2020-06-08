#include <cassert>
#include <iostream>

using namespace std;

/**
 *  n        | n-1
 *  1 000001 |   0 000000
 *  2 000010 |   1 000001
 *  4 000100 |   3 000011
 *  8 001000 |   7 000111
 * 16 010000 |  15 001111
 * 32 100000 |  31 011111
 */
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return !(n & (n - 1));
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
