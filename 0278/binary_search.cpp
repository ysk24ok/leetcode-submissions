#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

bool isBadVersion(int version) {
  return version >= 4;
}

class Solution {
 public:
  int firstBadVersion(int n) {
    int left = 0, right = n;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      bool ret = isBadVersion(mid);
      if (ret) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

int main() {
  Solution sol;

  ExpectEqual(4, sol.firstBadVersion(5));
}
