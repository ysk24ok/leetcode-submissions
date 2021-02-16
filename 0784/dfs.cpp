#include <gtest/gtest.h>

#include <cctype>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    permutation_ = {};
    dfs(S, 0, "");
    return permutation_;
  }

  void dfs(const string& S, size_t idx, const string& str) {
    if (idx == S.size()) {
      permutation_.push_back(str);
      return;
    }
    if (islower(S[idx])) {
      dfs(S, idx + 1, str + S[idx]);
      dfs(S, idx + 1, str + static_cast<char>(toupper(S[idx])));
    } else if (isupper(S[idx])) {
      dfs(S, idx + 1, str + static_cast<char>(tolower(S[idx])));
      dfs(S, idx + 1, str + S[idx]);
    } else {
      dfs(S, idx + 1, str + S[idx]);
    }
  }

 private:
  vector<string> permutation_;
};

int main() {
  Solution sol;
  string S;
  vector<string> expected;

  S = "a1b2", expected = {"a1b2", "a1B2", "A1b2", "A1B2"};
  EXPECT_EQ(expected, sol.letterCasePermutation(S));

  S = "3z4", expected = {"3z4", "3Z4"};
  EXPECT_EQ(expected, sol.letterCasePermutation(S));

  S = "12345", expected = {"12345"};
  EXPECT_EQ(expected, sol.letterCasePermutation(S));

  S = "0", expected = {"0"};
  EXPECT_EQ(expected, sol.letterCasePermutation(S));

  exit(EXIT_SUCCESS);
}
