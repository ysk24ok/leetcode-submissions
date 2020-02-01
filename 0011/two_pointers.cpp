#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    int cur_area;
    while (left < right) {
      cur_area = min(height[left], height[right]) * (right - left);
      max_area = max(cur_area, max_area);
      if (height[left] < height[right]) left++;
      else right--;
    }
    return max_area;
  }
};

int main() {
  Solution sol;
  vector<int> height;

  height = {1,8,6,2,5,4,8,3,7};
  assert(sol.maxArea(height) == 49);

  height = {};
  assert(sol.maxArea(height) == 0);

  height = {4,3,2,1};
  assert(sol.maxArea(height) == 4);
}
