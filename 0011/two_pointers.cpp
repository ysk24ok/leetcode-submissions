#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int max_area = 0;
    int cur_area;
    while (l < r) {
      cur_area = min(height[l], height[r]) * (r - l);
      max_area = max(cur_area, max_area);
      if (height[l] < height[r]) l++;
      else r--;
    }
    return max_area;
  }
};

int main() {
  Solution sol;
  vector<int> height;

  height = {1,8,6,2,5,4,8,3,7};
  EXPECT_EQ(sol.maxArea(height), 49);

  height = {};
  EXPECT_EQ(sol.maxArea(height), 0);

  height = {4,3,2,1};
  EXPECT_EQ(sol.maxArea(height), 4);

  exit(EXIT_SUCCESS);
}
