#include <unordered_map>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;  // key: sum(0, j), value: count
    int ret = 0;
    int sum = 0;  // holds sum(0, i)
    map[0] = 1;
    for (size_t i = 0, n = nums.size(); i < n; ++i) {
      sum += nums[i];
      // if sum(0, i) - sum(0, j) == k
      if (map.find(sum - k) != map.end()) {
        ret += map[sum - k];
      }
      map[sum]++;
    }
    return ret;
  }
};

int main() {
  Solution sol;

  vector<int> nums;
  int k;

  nums = {1,1,1};
  k = 2;
  ExpectEqual(2, sol.subarraySum(nums, k));

  nums = {1,1,2,2};
  k = 4;
  ExpectEqual(2, sol.subarraySum(nums, k));

  nums = {1,2,1,2,1};
  k = 3;
  ExpectEqual(4, sol.subarraySum(nums, k));
}
