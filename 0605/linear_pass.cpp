#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int prev = -1;
    for (int i = 0; i < flowerbed.size(); ++i) {
      if (flowerbed[i] == 0) { continue; }
      if (prev == -1) {
        n -= i / 2;
      } else {
        n -= (i - prev - 1 - 1) / 2;
      }
      prev = i;
    }
    // all zero
    if (prev == -1) {
      n -= (flowerbed.size() + 1) / 2;
    } else {
      n -= (flowerbed.size() - 1 - prev) / 2;
    }
    return n <= 0;
  }
};

int main() {
  Solution sol;
  vector<int> flowerbed;
  int n;
  bool expected;

  flowerbed = {1, 0, 0, 0, 1}, n = 1;
  expected = true;
  EXPECT_EQ(expected, sol.canPlaceFlowers(flowerbed, n));

  flowerbed = {1, 0, 0, 0, 1}, n = 2;
  expected = false;
  EXPECT_EQ(expected, sol.canPlaceFlowers(flowerbed, n));

  flowerbed = {0, 0, 0, 0}, n = 2;
  expected = true;
  EXPECT_EQ(expected, sol.canPlaceFlowers(flowerbed, n));

  flowerbed = {0, 0, 1, 0, 0}, n = 1;
  expected = true;
  EXPECT_EQ(expected, sol.canPlaceFlowers(flowerbed, n));

  exit(EXIT_SUCCESS);
}
