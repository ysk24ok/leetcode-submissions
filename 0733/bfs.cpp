#include <queue>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    queue<pair<int, int>> q;
    const size_t m = image.size(), n = image[0].size();
    const int original_color = image[sr][sc];
    q.push({sr, sc});
    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      if (p.first < 0 || p.first >= m || p.second < 0 || p.second >= n) { continue; }
      if (image[p.first][p.second] != original_color || image[p.first][p.second] == newColor) { continue; }
      image[p.first][p.second] = newColor;
      q.push({p.first-1, p.second});
      q.push({p.first+1, p.second});
      q.push({p.first, p.second-1});
      q.push({p.first, p.second+1});
    }
    return image;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> image, expected;
  int sr, sc, newColor;

  image = {
    {1,1,1},
    {1,1,0},
    {1,0,1}
  };
  expected = {
    {2,2,2},
    {2,2,0},
    {2,0,1}
  };
  sr = 1, sc = 1, newColor = 2;
  ExpectMatrixEqual(expected, sol.floodFill(image, sr, sc, newColor));

  image = {
    {0,0,0},
    {0,1,1}
  };
  expected = {
    {0,0,0},
    {0,1,1}
  };
  sr = 1, sc = 1, newColor = 1;
  ExpectMatrixEqual(expected, sol.floodFill(image, sr, sc, newColor));
}
