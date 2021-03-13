#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_set>

using namespace std;

// Say N = the size of the string,
// time complexity: O(N * k) (string::substr takes O(K))
// space complexity: O(k * 2^k)
class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    if (k > s.size()) {
      return false;
    }
    unordered_set<string> binary_codes;
    for (size_t i = 0; i <= s.size() - k; ++i) {
      binary_codes.insert(s.substr(i, k));
    }
    return binary_codes.size() == pow(2, k);
  }
};

int main() {
  Solution sol;
  string s;
  int k;
  bool expected;

  s = "00110110", k = 2, expected = true;
  EXPECT_EQ(expected, sol.hasAllCodes(s, k));

  s = "00110", k = 2, expected = true;
  EXPECT_EQ(expected, sol.hasAllCodes(s, k));

  s = "0110", k = 1, expected = true;
  EXPECT_EQ(expected, sol.hasAllCodes(s, k));

  s = "0110", k = 2, expected = false;
  EXPECT_EQ(expected, sol.hasAllCodes(s, k));

  s = "0000000001011100", k = 4, expected = false;
  EXPECT_EQ(expected, sol.hasAllCodes(s, k));

  s = "0101", k = 13, expected = false;
  EXPECT_EQ(expected, sol.hasAllCodes(s, k));

  exit(EXIT_SUCCESS);
}
