#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int distributeCandies(vector<int>& candyType) {
    unordered_set<int> unique_candy_type;
    for (const int& candy_type : candyType) {
      unique_candy_type.insert(candy_type);
    }
    return min(candyType.size() / 2, unique_candy_type.size());
  }
};

int main() {
  Solution sol;
  vector<int> candyType;
  int expected;

  candyType = {1, 1, 2, 2, 3, 3}, expected = 3;
  EXPECT_EQ(expected, sol.distributeCandies(candyType));

  candyType = {1, 1, 2, 3}, expected = 2;
  EXPECT_EQ(expected, sol.distributeCandies(candyType));

  candyType = {6, 6, 6, 6}, expected = 1;
  EXPECT_EQ(expected, sol.distributeCandies(candyType));

  exit(EXIT_SUCCESS);
}
