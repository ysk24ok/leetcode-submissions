#include <cassert>

using namespace std;

class Solution {
 public:
  bool isPerfectSquare(int num) {
    int left = 1;
    int right = num;
    // TODO
    if (right > 46340) { right = 46340; }
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      int square = mid * mid;
      if (square < num) {
        left = mid + 1;
      } else if (square > num) {
        right = mid - 1;
      } else { return true; }
    }
    return false;
  }
};

int main() {
  Solution sol;
  assert(sol.isPerfectSquare(1));
  assert(!sol.isPerfectSquare(2));
  assert(!sol.isPerfectSquare(3));
  assert(sol.isPerfectSquare(4));
  assert(!sol.isPerfectSquare(5));
  assert(!sol.isPerfectSquare(6));
  assert(!sol.isPerfectSquare(7));
  assert(!sol.isPerfectSquare(8));
  assert(sol.isPerfectSquare(9));
  assert(!sol.isPerfectSquare(10));
  assert(!sol.isPerfectSquare(11));
  assert(!sol.isPerfectSquare(12));
  assert(!sol.isPerfectSquare(13));
  assert(!sol.isPerfectSquare(14));
  assert(!sol.isPerfectSquare(15));
  assert(sol.isPerfectSquare(16));
  assert(!sol.isPerfectSquare(2147483647));
}
