#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int P) {
    sort(tokens.begin(), tokens.end());
    int left = 0, right = tokens.size() - 1;
    int score = 0;
    while (left <= right) {
      // face up
      while (left < tokens.size() && P >= tokens[left]) {
        P -= tokens[left++];
        score++;
      }
      if (left >= right) { break; }
      // face down
      if (score > 0) {
        P += tokens[right];
        score--;
      }
      right--;
    }
    return score;
  }
};

int main() {
  Solution sol;
  vector<int> tokens;
  int P, expected;

  tokens = {100}, P = 50, expected = 0;
  EXPECT_EQ(expected, sol.bagOfTokensScore(tokens, P));

  tokens = {100, 200}, P = 150, expected = 1;
  EXPECT_EQ(expected, sol.bagOfTokensScore(tokens, P));

  tokens = {100, 200, 300, 400}, P = 200, expected = 2;
  EXPECT_EQ(expected, sol.bagOfTokensScore(tokens, P));

  tokens = {26}, P = 51, expected = 1;
  EXPECT_EQ(expected, sol.bagOfTokensScore(tokens, P));

  tokens = {58, 91}, P = 50, expected = 0;
  EXPECT_EQ(expected, sol.bagOfTokensScore(tokens, P));

  tokens = {81, 91, 31}, P = 73, expected = 1;
  EXPECT_EQ(expected, sol.bagOfTokensScore(tokens, P));

  exit(EXIT_SUCCESS);
}
