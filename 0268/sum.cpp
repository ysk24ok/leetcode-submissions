#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int original_sum = (1 + n) * n / 2;
    int real_sum = accumulate(nums.begin(), nums.end(), 0);
    return original_sum - real_sum;
  }
};

int main() {
  Solution sol;
  vector<int> d;

  d = {3, 0, 1};
  assert(sol.missingNumber(d) == 2);

  d = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  assert(sol.missingNumber(d) == 8);
}
