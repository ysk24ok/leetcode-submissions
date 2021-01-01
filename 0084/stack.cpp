#include <gtest/gtest.h>

#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    const int n = heights.size();
    if (n == 0) { return 0; }
    heights.push_back(0);
    // The stack contains bars whose lengths are in ascending order
    stack<int> st;
    int ret = 0;
    st.push(0);
    for (int i = 1; i <= n; ++i) {
      while (!st.empty() && heights[st.top()] > heights[i]) {
        int height = heights[st.top()];
        st.pop();
        // Say st.top() = j.
        // Because the stack contains bars whose lengths are in ascending order,
        // * `heights[j] < height`
        // * `heights[j+1] >= height`
        // ...
        // * `heights[i-1] >= height`
        // so the width is `i-j-1`.
        int width = !st.empty() ? i - st.top() - 1 : i;
        ret = max(height * width, ret);
      }
      st.push(i);
    }
    heights.pop_back();
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> heights;
  int expected;

  heights = {2, 1, 5, 6, 2, 3};
  expected = 10;
  EXPECT_EQ(expected, sol.largestRectangleArea(heights));

  heights = {2};
  expected = 2;
  EXPECT_EQ(expected, sol.largestRectangleArea(heights));

  heights = {};
  expected = 0;
  EXPECT_EQ(expected, sol.largestRectangleArea(heights));

  heights = {1, 2, 2, 3};
  expected = 6;
  EXPECT_EQ(expected, sol.largestRectangleArea(heights));

  heights = {2, 1, 2};
  expected = 3;
  EXPECT_EQ(expected, sol.largestRectangleArea(heights));

  exit(EXIT_SUCCESS);
}
