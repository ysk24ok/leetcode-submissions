#include <algorithm>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& A) {
    int total = 0;
    int sum_max = -30000, current_max = 0, sum_min = 30000, current_min = 0;
    for (const auto& a : A) {
      current_max = max(current_max, 0) + a;
      sum_max = max(sum_max, current_max);
      current_min = min(current_min, 0) + a;
      sum_min = min(sum_min, current_min);
      total += a;
    }
    if (total != sum_min) {
      return max(sum_max, total - sum_min);
    } else {
      return sum_max;
    }
  }
};

int main() {
  Solution sol;
  vector<int> A;

  A = {1,-2,3,-2};
  ExpectEqual(3, sol.maxSubarraySumCircular(A));

  A = {5,-3,5};
  ExpectEqual(10, sol.maxSubarraySumCircular(A));

  A = {3,-1,2,-1};
  ExpectEqual(4, sol.maxSubarraySumCircular(A));

  A = {3,-2,2,-3};
  ExpectEqual(3, sol.maxSubarraySumCircular(A));

  A = {-2,-3,-1};
  ExpectEqual(-1, sol.maxSubarraySumCircular(A));

  A = {-2,-3,1};
  ExpectEqual(1, sol.maxSubarraySumCircular(A));
}
