#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> ret;
    for (size_t i = 0; i < nums.size(); ++i) {
      ret.insert(ret.begin() + index[i], nums[i]);
    }
    return ret;
  }
};

void assert_vector_equal(const vector<int>& expected, const vector<int>& got) {
  assert(expected.size() == got.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    assert(expected[i] == got[i]);
  }
}

int main() {
  Solution sol;
  vector<int> nums, index, got, expected;

  nums = {0,1,2,3,4};
  index = {0,1,2,2,1};
  expected = {0,4,1,3,2};
  got = sol.createTargetArray(nums, index);
  assert_vector_equal(expected, got);

  nums = {1,2,3,4,0};
  index = {0,1,2,3,0};
  expected = {0,1,2,3,4};
  got = sol.createTargetArray(nums, index);
  assert_vector_equal(expected, got);

  nums = {1};
  index = {0};
  expected = {1};
  got = sol.createTargetArray(nums, index);
  assert_vector_equal(expected, got);
}
