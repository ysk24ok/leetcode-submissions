#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

/**
 *   - h o r s e
 * - 0 1 2 3 4 5
 * r 1 1 2 2 3 4
 * o 2 2 1 2 3 4
 * s 3 2 2 1 2 3
 */

class Solution {
 public:
  int minDistance(string word1, string word2) {
    const size_t m = word2.size(), n = word1.size();
    vector<int> prev(n+1), curr(n+1);
    for (size_t j = 0; j <= n; ++j) { prev[j] = j; }
    for (size_t i = 1; i <= m; ++i) {
      curr[0] = i;
      const char& c2 = word2[i-1];
      for (size_t j = 1; j <= n; ++j) {
        if (word1[j-1] == c2) {
          curr[j] = prev[j-1];
        } else {
          curr[j] = min({prev[j-1] + 1, prev[j] + 1, curr[j-1] + 1});
        }
      }
      prev.swap(curr);
    }
    return prev[n];
  }
};

int main() {
  Solution sol;
  string word1, word2;

  word1 = "horse", word2 = "ros";
  EXPECT_EQ(3, sol.minDistance(word1, word2));

  word1 = "intention", word2 = "execution";
  EXPECT_EQ(5, sol.minDistance(word1, word2));

  exit(EXIT_SUCCESS);
}
