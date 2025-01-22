#include <gtest/gtest.h>

#include <vector>

using namespace std;

int dp[100][100][100];

class Solution {
 public:
  int removeBoxes(vector<int>& boxes) {
    memset(dp, 0, sizeof(dp));
    return dfs(boxes, 0, boxes.size() - 1, 0);
  }

 private:
  int dfs(const vector<int>& boxes, int l, int r, int k) {
    // `k` is the number of boxes which are the same color as `boxes[l]`
    // and exist on the left of `l`
    if (l > r) {
      return 0;
    }
    if (dp[l][r][k] != 0) {
      return dp[l][r][k];
    }
    // grouping all boxes of the same color from the left
    // boxes: {3, 3, 2, 4, 3, 2}, k = 1
    //            l           r
    for (; l + 1 <= r && boxes[l + 1] == boxes[l]; l++, k++);
    dp[l][r][k] = dfs(boxes, l + 1, r, 0) + (k + 1) * (k + 1);
    for (int m = l + 1; m <= r; m++) {
      if (boxes[l] == boxes[m]) {
        dp[l][r][k] = max(
          dp[l][r][k],
          dfs(boxes, l + 1, m - 1, 0) + dfs(boxes, m, r, k + 1)
        );
      }
    }
    return dp[l][r][k];
  }
};

int main() {
  Solution sol;
  vector<int> boxes;
  int expected;

  boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1}, expected = 23;
  EXPECT_EQ(expected, sol.removeBoxes(boxes));

  boxes = {1, 1, 1}, expected = 9;
  EXPECT_EQ(expected, sol.removeBoxes(boxes));

  boxes = {1}, expected = 1;
  EXPECT_EQ(expected, sol.removeBoxes(boxes));

  // XXX: TLE
  boxes = {1,2,2,1,1,1,2,1,1,2,1,2,1,1,2,2,1,1,2,2,1,1,1,2,2,2,2,1,2,1,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,1,1,2,2,1,2,1,2,2,1,2,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,2,1,2,2,1};
  sol.removeBoxes(boxes);

  exit(EXIT_SUCCESS);
}
