#include <gtest/gtest.h>

#include <cctype>
#include <cstdlib>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ret;
    queue<pair<string, size_t>> q;
    q.push({"", 0});
    while (!q.empty()) {
      string str = q.front().first;
      size_t idx = q.front().second;
      q.pop();
      if (idx == S.size()) {
        ret.push_back(str);
        continue;
      }
      if (islower(S[idx])) {
        q.push({str + S[idx], idx + 1});
        q.push({str + static_cast<char>(toupper(S[idx])), idx + 1});
      } else if (isupper(S[idx])) {
        q.push({str + static_cast<char>(tolower(S[idx])), idx + 1});
        q.push({str + S[idx], idx + 1});
      } else {
        q.push({str + S[idx], idx + 1});
      }
    }
    return ret;
  }
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
