#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int l = 1, r = m * n;
    int mid;
    int count;
    while (l < r) {
      mid = l + (r - l) / 2;
      count = total(m, n, mid);
      if (count < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }

  int total(int m, int n, int threshold) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
      count += min(threshold / i, m);
    }
    return count;
  }
};

int main() {
  Solution sol;
  // 1  2  3
  // 2  4  6
  // 3  6  9
  assert(sol.findKthNumber(3, 3, 5) == 3);
  assert(sol.findKthNumber(2, 3, 6) == 6);
  // 1  2  3  4
  // 2  4  6  8
  // 3  6  9 12
  // 4  8 12 16
  assert(sol.findKthNumber(4, 4, 1) == 1);
  assert(sol.findKthNumber(4, 4, 2) == 2);
  assert(sol.findKthNumber(4, 4, 3) == 2);
  assert(sol.findKthNumber(4, 4, 4) == 3);
  assert(sol.findKthNumber(4, 4, 5) == 3);
  assert(sol.findKthNumber(4, 4, 6) == 4);
  assert(sol.findKthNumber(4, 4, 7) == 4);
  assert(sol.findKthNumber(4, 4, 8) == 4);
  assert(sol.findKthNumber(4, 4, 9) == 6);
  assert(sol.findKthNumber(4, 4, 10) == 6);
  assert(sol.findKthNumber(4, 4, 11) == 8);
  assert(sol.findKthNumber(4, 4, 12) == 8);
  assert(sol.findKthNumber(4, 4, 13) == 9);
  assert(sol.findKthNumber(4, 4, 14) == 12);
  assert(sol.findKthNumber(4, 4, 15) == 12);
  assert(sol.findKthNumber(4, 4, 16) == 16);
}
