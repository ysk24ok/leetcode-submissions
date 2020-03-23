#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumFourDivisors(vector<int>& nums) {
    int ret = 0;
    for (const auto& num : nums) {
      if (num == 1) continue;
      int count = 0;
      int sum = 0;
      for (int i = 1; i * i <= num; ++i) {
        if (num % i != 0) continue;
        if (count > 4) continue;
        int div = num / i;
        assert(i <= div);
        if (i == div) {
          count++;
          sum += i;
        } else {
          count += 2;
          sum += (i + div);
        }
      }
      if (count == 4) ret += sum;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {21,4,7};
  assert(sol.sumFourDivisors(nums) == 32);

  // 1,2,4,8,16
  nums = {16};
  assert(sol.sumFourDivisors(nums) == 0);
}
