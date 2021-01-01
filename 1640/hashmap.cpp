#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    unordered_map<int, size_t> map;
    for (size_t i = 0; i < pieces.size(); ++i) {
      map[pieces[i][0]] = i;
    }
    for (size_t i = 0; i < arr.size();) {
      if (map.find(arr[i]) == map.end()) { return false; }
      size_t piece_idx = map[arr[i]];
      for (const auto& val : pieces[piece_idx]) {
        if (arr[i] != val) { return false; }
        ++i;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<int> arr;
  vector<vector<int>> pieces;
  bool expected;

  arr = {85}, pieces = {{85}}, expected = true;
  EXPECT_EQ(expected, sol.canFormArray(arr, pieces));

  arr = {15, 88}, pieces = {{88}, {15}}, expected = true;
  EXPECT_EQ(expected, sol.canFormArray(arr, pieces));

  arr = {49, 18, 16}, pieces = {{16, 18, 49}}, expected = false;
  EXPECT_EQ(expected, sol.canFormArray(arr, pieces));

  arr = {91, 4, 64, 78}, pieces = {{78}, {4, 64}, {91}}, expected = true;
  EXPECT_EQ(expected, sol.canFormArray(arr, pieces));

  exit(EXIT_SUCCESS);
}
